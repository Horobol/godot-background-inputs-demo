#include "../../BackgroundInputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <windows.h>

using namespace godot;

void BackgroundInputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::ARRAY, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
	// Fn keys
	keys[VK_F1] = KEY_F1;
	keys[VK_F2] = KEY_F2;
	keys[VK_F3] = KEY_F3;
	keys[VK_F4] = KEY_F4;
	keys[VK_F5] = KEY_F5;
	keys[VK_F6] = KEY_F6;
	keys[VK_F7] = KEY_F7;
	keys[VK_F8] = KEY_F8;
	keys[VK_F9] = KEY_F9;
	keys[VK_F10] = KEY_F10;
	keys[VK_F11] = KEY_F11;
	keys[VK_F12] = KEY_F12;
	keys[VK_F13] = KEY_F13;
	keys[VK_F14] = KEY_F14;
	keys[VK_F15] = KEY_F15;
	keys[VK_F16] = KEY_F16;
	keys[VK_F17] = KEY_F17;
	keys[VK_F18] = KEY_F18;
	keys[VK_F19] = KEY_F19;
	keys[VK_F20] = KEY_F20;
	keys[VK_F21] = KEY_F21;
	keys[VK_F22] = KEY_F22;
	keys[VK_F23] = KEY_F23;
	keys[VK_F24] = KEY_F24;

	// Control keys
	keys[VK_LCONTROL] = KEY_CTRL;
	keys[VK_RCONTROL] = KEY_CTRL;
	keys[VK_LSHIFT] = KEY_SHIFT;
	keys[VK_RSHIFT] = KEY_SHIFT;
	keys[VK_LMENU] = KEY_ALT;
	keys[VK_RMENU] = KEY_ALT;
	keys[VK_TAB] = KEY_TAB;
	keys[VK_SPACE] = KEY_SPACE;
	keys[VK_BACK] = KEY_BACKSPACE;
	keys[VK_INSERT] = KEY_INSERT;
	keys[VK_DELETE] = KEY_DELETE;
	keys[VK_HOME] = KEY_HOME;
	keys[VK_END] = KEY_END;
	keys[VK_PRIOR] = KEY_PAGEUP;
	keys[VK_NEXT] = KEY_PAGEDOWN;

	// Arrow keys
	keys[VK_UP] = KEY_UP;
	keys[VK_DOWN] = KEY_DOWN;
	keys[VK_LEFT] = KEY_LEFT;
	keys[VK_RIGHT] = KEY_RIGHT;

	// Numpad keys
	keys[VK_NUMPAD0] = KEY_KP_0;
	keys[VK_NUMPAD1] = KEY_KP_1;
	keys[VK_NUMPAD2] = KEY_KP_2;
	keys[VK_NUMPAD3] = KEY_KP_3;
	keys[VK_NUMPAD4] = KEY_KP_4;
	keys[VK_NUMPAD5] = KEY_KP_5;
	keys[VK_NUMPAD6] = KEY_KP_6;
	keys[VK_NUMPAD7] = KEY_KP_7;
	keys[VK_NUMPAD8] = KEY_KP_8;
	keys[VK_NUMPAD9] = KEY_KP_9;
	keys[VK_NUMLOCK] = KEY_NUMLOCK;
	keys[VK_ADD] = KEY_KP_ADD;
	keys[VK_SUBTRACT] = KEY_KP_SUBTRACT;
	keys[VK_MULTIPLY] = KEY_KP_MULTIPLY;
	keys[VK_DIVIDE] = KEY_KP_DIVIDE;
	keys[VK_DECIMAL] = KEY_KP_PERIOD;

	// Letters (these map out to the same as Godot)
	for (int i = KEY_A; i <= KEY_Z; i++) keys[i] = i;

	// Numbers (these also map out to the same as Godot)
	for (int i = KEY_0; i <= KEY_9; i++) keys[i] = i;

	// Mouse buttons
	keys[VK_LBUTTON] = MOUSE_BUTTON_LEFT;
	keys[VK_RBUTTON] = MOUSE_BUTTON_RIGHT;
	keys[VK_MBUTTON] = MOUSE_BUTTON_MIDDLE;
	keys[VK_XBUTTON1] = MOUSE_BUTTON_XBUTTON1;
	keys[VK_XBUTTON2] = MOUSE_BUTTON_XBUTTON2;
}

BackgroundInputCapture::~BackgroundInputCapture() {
	// Add your cleanup here.
}

void BackgroundInputCapture::_process(double delta) {
	Array keys_pressed{};

	for (auto const &[key, value] : keys) {
		if (GetAsyncKeyState(key) & KF_UP) {
			keys_pressed.push_back(value);
		}
	}

	if (!keys_pressed.is_empty()) {
		emit_signal("bg_key_pressed", this, keys_pressed);
	}
}
