#include "Win32InputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <windows.h>

using namespace godot;

void Win32InputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING, "key_pressed")));
}

Win32InputCapture::Win32InputCapture() {
	keys[VK_F1] = "F1";
	keys[VK_F2] = "F2";
	keys[VK_F3] = "F3";
	keys[VK_F4] = "F4";
	keys[VK_F5] = "F5";
	keys[VK_F6] = "F6";
	keys[VK_F7] = "F7";
	keys[VK_F8] = "F8";
	keys[VK_F9] = "F9";
	keys[VK_F10] = "F10";
	keys[VK_F11] = "F11";
	keys[VK_F12] = "F12";
}

Win32InputCapture::~Win32InputCapture() {
	// Add your cleanup here.
}

void Win32InputCapture::_process(double delta) {
	for (int key = VK_F1; key <= VK_F12; key++) {
		if (GetAsyncKeyState(key)) {
			emit_signal("bg_key_pressed", this, keys[key].c_str());
		}
	}
}