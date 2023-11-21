#include "../../BackgroundInputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

using namespace godot;

static const char *const evval[3] = {
	"RELEASED",
	"PRESSED ",
	"REPEATED"
};

void BackgroundInputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    fd = open(dev, O_RDONLY);
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
    
    if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2) {
    	emit_signal("bg_key_pressed", this, std::to_string((int) ev.code).c_str());
    }
}
