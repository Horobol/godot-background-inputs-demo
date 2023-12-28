#include "../../BackgroundInputCapture.h"
#include "./UnixInputEventCodes.h"
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
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::DICTIONARY, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
	
	// Fn keys
	keys[PH_KEY_F1] = KEY_F1;
	keys[PH_KEY_F2] = KEY_F2;
	keys[PH_KEY_F3] = KEY_F3;
	keys[PH_KEY_F4] = KEY_F4;
	keys[PH_KEY_F5] = KEY_F5;
	keys[PH_KEY_F6] = KEY_F6;
	keys[PH_KEY_F7] = KEY_F7;
	keys[PH_KEY_F8] = KEY_F8;
	keys[PH_KEY_F9] = KEY_F9;
	keys[PH_KEY_F10] = KEY_F10;
	keys[PH_KEY_F11] = KEY_F11;
	keys[PH_KEY_F12] = KEY_F12;
	keys[PH_KEY_F13] = KEY_F13;
	keys[PH_KEY_F14] = KEY_F14;
	keys[PH_KEY_F15] = KEY_F15;
	keys[PH_KEY_F16] = KEY_F16;
	keys[PH_KEY_F17] = KEY_F17;
	keys[PH_KEY_F18] = KEY_F18;
	keys[PH_KEY_F19] = KEY_F19;
	keys[PH_KEY_F20] = KEY_F20;
	keys[PH_KEY_F21] = KEY_F21;
	keys[PH_KEY_F22] = KEY_F22;
	keys[PH_KEY_F23] = KEY_F23;
	keys[PH_KEY_F24] = KEY_F24;

	// Control keys
	keys[PH_KEY_LEFTCTRL] = KEY_CTRL;
	keys[PH_KEY_RIGHTCTRL] = KEY_CTRL;
	keys[PH_KEY_LEFTSHIFT] = KEY_SHIFT;
	keys[PH_KEY_RIGHTSHIFT] = KEY_SHIFT;
	keys[PH_KEY_LEFTALT] = KEY_ALT;
	keys[PH_KEY_RIGHTALT] = KEY_ALT;
	keys[PH_KEY_TAB] = KEY_TAB;
	keys[PH_KEY_SPACE] = KEY_SPACE;
	keys[PH_KEY_BACK] = KEY_BACKSPACE;
	keys[PH_KEY_INSERT] = KEY_INSERT;
	keys[PH_KEY_DELETE] = KEY_DELETE;
	keys[PH_KEY_HOME] = KEY_HOME;
	keys[PH_KEY_END] = KEY_END;
	keys[PH_KEY_PAGEUP] = KEY_PAGEUP;
	keys[PH_KEY_PAGEDOWN] = KEY_PAGEDOWN;

	// Arrow keys
	keys[PH_KEY_UP] = KEY_UP;
	keys[PH_KEY_DOWN] = KEY_DOWN;
	keys[PH_KEY_LEFT] = KEY_LEFT;
	keys[PH_KEY_RIGHT] = KEY_RIGHT;

	// Numpad keys
	keys[PH_KEY_KP0] = KEY_KP_0;
	keys[PH_KEY_KP1] = KEY_KP_1;
	keys[PH_KEY_KP2] = KEY_KP_2;
	keys[PH_KEY_KP3] = KEY_KP_3;
	keys[PH_KEY_KP4] = KEY_KP_4;
	keys[PH_KEY_KP5] = KEY_KP_5;
	keys[PH_KEY_KP6] = KEY_KP_6;
	keys[PH_KEY_KP7] = KEY_KP_7;
	keys[PH_KEY_KP8] = KEY_KP_8;
	keys[PH_KEY_KP9] = KEY_KP_9;
	keys[PH_KEY_NUMLOCK] = KEY_NUMLOCK;
	keys[PH_KEY_KPPLUS] = KEY_KP_ADD;
	keys[PH_KEY_KPMINUS] = KEY_KP_SUBTRACT;
	keys[PH_KEY_KPASTERISK] = KEY_KP_MULTIPLY;
	keys[PH_KEY_KPSLASH] = KEY_KP_DIVIDE;
	keys[PH_KEY_KPDOT] = KEY_KP_PERIOD;
	keys[PH_KEY_KPENTER] = KEY_KP_ENTER;

	// Letters
	keys[PH_KEY_Q] = KEY_Q;
	keys[PH_KEY_W] = KEY_W;
	keys[PH_KEY_E] = KEY_E;
	keys[PH_KEY_R] = KEY_R;
	keys[PH_KEY_T] = KEY_T;
	keys[PH_KEY_Y] = KEY_Y;
	keys[PH_KEY_U] = KEY_U;
	keys[PH_KEY_I] = KEY_I;
	keys[PH_KEY_O] = KEY_O;
	keys[PH_KEY_P] = KEY_P;
	keys[PH_KEY_A] = KEY_A;
	keys[PH_KEY_S] = KEY_S;
	keys[PH_KEY_D] = KEY_D;
	keys[PH_KEY_F] = KEY_F;
	keys[PH_KEY_G] = KEY_G;
	keys[PH_KEY_H] = KEY_H;
	keys[PH_KEY_J] = KEY_J;
	keys[PH_KEY_K] = KEY_K;
	keys[PH_KEY_L] = KEY_L;
	keys[PH_KEY_Z] = KEY_Z;
	keys[PH_KEY_X] = KEY_X;
	keys[PH_KEY_C] = KEY_C;
	keys[PH_KEY_V] = KEY_V;
	keys[PH_KEY_B] = KEY_B;
	keys[PH_KEY_N] = KEY_N;
	keys[PH_KEY_M] = KEY_M;

	// Numbers
	keys[PH_KEY_0] = KEY_0;
	for (int i = 0; i <= PH_KEY_9 - PH_KEY_1; i++) keys[PH_KEY_1 + i] = KEY_1 + i;

	for (auto const &[key, value] : keys) {
		pressed[value] = false;
	}

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
  		keyboardFd = -1;
  		return;
  	}

  	//Choose device with the best score
  	int max_device = std::max_element(scores.begin(), scores.end()) - scores.begin();
  	std::string input_device = devices[max_device];  // for now, use only the first found device
  	
    keyboardFd = open(input_device.c_str(), O_RDONLY | O_NONBLOCK);
}

BackgroundInputCapture::~BackgroundInputCapture() {
	close(keyboardFd);
}

void BackgroundInputCapture::_process(double delta) {
	bool has_changed = false;

	if (keyboardFd == -1) {
		return;
	}
    
    struct input_event ev[5];
    ssize_t n;
    
    n = read(keyboardFd, &ev, sizeof(struct input_event) * 5);
    
    if (n == (ssize_t) - 1) {
        if (errno == EINTR)
            return;
        else
            return;
    } else
    if (n < sizeof(struct input_event)) {
        errno = EIO;
        return;
    }
    
	for (int i = 0; i < 5; i++) {
		if (ev[i].type == EV_KEY && keys.find(ev[i].code) != keys.end()) {
			if (ev[i].value == 1) {
				pressed[keys[ev[i].code]] = true;
				has_changed = true;
			} else if (ev[i].value == 0) {
				pressed[keys[ev[i].code]] = false;
				has_changed = true;
			}
		}
	}

	if (has_changed) {
		emit_signal("bg_key_pressed", this, pressed);
	}
}
