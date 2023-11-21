#include "../../BackgroundInputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace godot;

std::string execute(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) { return ""; }
    char buffer[128];
    std::string result = "";
    while(!feof(pipe))
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    pclose(pipe);
    return result;
}

void BackgroundInputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
	keys[59] = "F1";
	keys[60] = "F2";
	keys[61] = "F3";
	keys[62] = "F4";
	keys[63] = "F5";
	keys[64] = "F6";
	keys[65] = "F7";
	keys[66] = "F8";
	keys[67] = "F9";
	keys[68] = "F10";
	keys[87] = "F11";
	keys[88] = "F12";

	//Look for devices with keybit bitmask that has keys a keyboard doeas
	//If a bitmask ends with 'e', it supports KEY_2, KEY_1, KEY_ESC, and KEY_RESERVED is set to 0, so it's probably a keyboard
	//keybit:   https://github.com/torvalds/linux/blob/02de58b24d2e1b2cf947d57205bd2221d897193c/include/linux/input.h#L45
	//keycodes: https://github.com/torvalds/linux/blob/139711f033f636cc78b6aaf7363252241b9698ef/include/uapi/linux/input-event-codes.h#L75
	//Take the Name, Handlers, and KEY values
	const char* cmd = "/bin/grep -B8 -E 'KEY=.*e$' /proc/bus/input/devices | /bin/grep -E 'Name|Handlers|KEY'";
	std::stringstream output(execute(cmd));
  
  	std::vector<std::string> devices;
  	std::vector<unsigned short> scores;
  	std::string line;
  
  	unsigned short line_type = 0;
  	unsigned short score = 0;

  	while(std::getline(output, line)) {
    	transform(line.begin(), line.end(), line.begin(), ::tolower);
 
    	//Generate score based on device name
    	if(line_type == 0) {
      		if (line.find("keyboard") != std::string::npos) {
        	score += 100;
      		}
    	}
    	//Add the event handler
    	else if(line_type == 1) {
      		std::string::size_type i = line.find("event");
      	if (i != std::string::npos) i += 5; // "event".size() == 5
		  	if (i < line.size()) {
		    	int index = atoi(&line.c_str()[i]);
		    
		    	if (index != -1) {
		      		std::stringstream input_dev_path;
				  	input_dev_path << "/dev/input/";
				  	input_dev_path << "event";
				  	input_dev_path << index;

		      		devices.push_back(input_dev_path.str());
		    	}
		  	}
    	}	
    	//Generate score based on size of key bitmask
    	else if (line_type == 2) {
		  	std::string::size_type i = line.find("=");
		  	std::string full_key_map = line.substr(i + 1);
		  	score += full_key_map.length();
		  	scores.push_back(score);
		  	score = 0;
		}
		
		line_type = (line_type + 1) % 3;
 	}
  
  	if (devices.size() == 0) {
  		fd = -1;
  		return;
  	}

  	//Choose device with the best score
  	int max_device = std::max_element(scores.begin(), scores.end()) - scores.begin();
  	std::string input_device = devices[max_device];  // for now, use only the first found device
  	
    fd = open(input_device.c_str(), O_RDONLY | O_NONBLOCK);
}

BackgroundInputCapture::~BackgroundInputCapture() {
	close(fd);
}

void BackgroundInputCapture::_process(double delta) {
	if (fd == -1) {
		return;
	}
    
    struct input_event ev;
    ssize_t n;
    
    n = read(fd, &ev, sizeof ev);
    
    if (n == (ssize_t) - 1) {
        if (errno == EINTR)
            return;
        else
            return;
    } else
    if (n != sizeof ev) {
        errno = EIO;
        return;
    }
    
    if (ev.type == EV_KEY && ev.value == 1) {
    	for (auto const &[key, value] : keys) {
    		if (key == ev.code) {
    			emit_signal("bg_key_pressed", this, value.c_str());
    		}
    	}
    }
}
