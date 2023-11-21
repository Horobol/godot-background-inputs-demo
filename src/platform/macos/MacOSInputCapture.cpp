#include "../../BackgroundInputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <ApplicationServices/ApplicationServices.h>

using namespace godot;

void BackgroundInputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
	keys[122] = "F1";
	keys[120] = "F2";
	keys[99] = "F3";
	keys[118] = "F4";
	keys[96] = "F5";
	keys[97] = "F6";
	keys[98] = "F7";
	keys[100] = "F8";
	keys[101] = "F9";
	keys[109] = "F10";
	keys[103] = "F11";
	keys[111] = "F12";
}

BackgroundInputCapture::~BackgroundInputCapture() {
	// Add your cleanup here.
}

void BackgroundInputCapture::_process(double delta) {
	for (auto const &[key, value] : keys) {
		if (CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, key)) {
			emit_signal("bg_key_pressed", this, value.c_str());
		}
	}
}
