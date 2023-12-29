#include "../../BackgroundInputCapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>

using namespace godot;

void BackgroundInputCapture::_bind_methods() {
	ADD_SIGNAL(MethodInfo("bg_key_pressed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::ARRAY, "key_pressed")));
}

BackgroundInputCapture::BackgroundInputCapture() {
	// Fn keys
	keys[kVK_F1] = KEY_F1;
	keys[kVK_F2] = KEY_F2;
	keys[kVK_F3] = KEY_F3;
	keys[kVK_F4] = KEY_F4;
	keys[kVK_F5] = KEY_F5;
	keys[kVK_F6] = KEY_F6;
	keys[kVK_F7] = KEY_F7;
	keys[kVK_F8] = KEY_F8;
	keys[kVK_F9] = KEY_F9;
	keys[kVK_F10] = KEY_F10;
	keys[kVK_F11] = KEY_F11;
	keys[kVK_F12] = KEY_F12;
	keys[kVK_F13] = KEY_F13;
	keys[kVK_F14] = KEY_F14;
	keys[kVK_F15] = KEY_F15;
	keys[kVK_F16] = KEY_F16;
	keys[kVK_F17] = KEY_F17;
	keys[kVK_F18] = KEY_F18;
	keys[kVK_F19] = KEY_F19;
	keys[kVK_F20] = KEY_F20;

	// Control keys
	keys[kVK_Control] = KEY_CTRL;
	keys[kVK_Shift] = KEY_SHIFT;
	keys[kVK_Option] = KEY_ALT;
	keys[kVK_Tab] = KEY_TAB;
	keys[kVK_Space] = KEY_SPACE;
	keys[kVK_Delete] = KEY_DELETE;
	keys[kVK_Home] = KEY_HOME;
	keys[kVK_End] = KEY_END;
	keys[kVK_PageUp] = KEY_PAGEUP;
	keys[kVK_PageDown] = KEY_PAGEDOWN;
	keys[kVK_Command] = KEY_MASK_META;

	// Arrow keys
	keys[kVK_UpArrow] = KEY_UP;
	keys[kVK_DownArrow] = KEY_DOWN;
	keys[kVK_LeftArrow] = KEY_LEFT;
	keys[kVK_RightArrow] = KEY_RIGHT;

	// Numpad keys
	keys[kVK_ANSI_Keypad0] = KEY_KP_0;
	keys[kVK_ANSI_Keypad1] = KEY_KP_1;
	keys[kVK_ANSI_Keypad2] = KEY_KP_2;
	keys[kVK_ANSI_Keypad3] = KEY_KP_3;
	keys[kVK_ANSI_Keypad4] = KEY_KP_4;
	keys[kVK_ANSI_Keypad5] = KEY_KP_5;
	keys[kVK_ANSI_Keypad6] = KEY_KP_6;
	keys[kVK_ANSI_Keypad7] = KEY_KP_7;
	keys[kVK_ANSI_Keypad8] = KEY_KP_8;
	keys[kVK_ANSI_Keypad9] = KEY_KP_9;
	keys[kVK_ANSI_KeypadPlus] = KEY_KP_ADD;
	keys[kVK_ANSI_KeypadPlus] = KEY_KP_SUBTRACT;
	keys[kVK_ANSI_KeypadMultiply] = KEY_KP_MULTIPLY;
	keys[kVK_ANSI_KeypadDivide] = KEY_KP_DIVIDE;
	keys[kVK_ANSI_KeypadDecimal] = KEY_KP_PERIOD;
	keys[kVK_ANSI_KeypadEnter] = KEY_KP_ENTER;

	// Letters
	keys[kVK_ANSI_Q] = KEY_Q;
	keys[kVK_ANSI_W] = KEY_W;
	keys[kVK_ANSI_E] = KEY_E;
	keys[kVK_ANSI_R] = KEY_R;
	keys[kVK_ANSI_T] = KEY_T;
	keys[kVK_ANSI_Y] = KEY_Y;
	keys[kVK_ANSI_U] = KEY_U;
	keys[kVK_ANSI_I] = KEY_I;
	keys[kVK_ANSI_O] = KEY_O;
	keys[kVK_ANSI_P] = KEY_P;
	keys[kVK_ANSI_A] = KEY_A;
	keys[kVK_ANSI_S] = KEY_S;
	keys[kVK_ANSI_D] = KEY_D;
	keys[kVK_ANSI_F] = KEY_F;
	keys[kVK_ANSI_G] = KEY_G;
	keys[kVK_ANSI_H] = KEY_H;
	keys[kVK_ANSI_J] = KEY_J;
	keys[kVK_ANSI_K] = KEY_K;
	keys[kVK_ANSI_L] = KEY_L;
	keys[kVK_ANSI_Z] = KEY_Z;
	keys[kVK_ANSI_X] = KEY_X;
	keys[kVK_ANSI_C] = KEY_C;
	keys[kVK_ANSI_V] = KEY_V;
	keys[kVK_ANSI_B] = KEY_B;
	keys[kVK_ANSI_N] = KEY_N;
	keys[kVK_ANSI_M] = KEY_M;

	// Numbers (why does MacOS shove the equal/minus randomly in numbers?)
	keys[kVK_ANSI_1] = KEY_1;
	keys[kVK_ANSI_2] = KEY_2;
	keys[kVK_ANSI_3] = KEY_3;
	keys[kVK_ANSI_4] = KEY_4;
	keys[kVK_ANSI_5] = KEY_5;
	keys[kVK_ANSI_6] = KEY_6;
	keys[kVK_ANSI_7] = KEY_7;
	keys[kVK_ANSI_8] = KEY_8;
	keys[kVK_ANSI_9] = KEY_9;
	keys[kVK_ANSI_0] = KEY_0;

	// Regional keys
	keys[kVK_ANSI_Semicolon] = KEY_SEMICOLON;
	keys[kVK_ANSI_Slash] = KEY_SLASH;
	keys[kVK_ANSI_Grave] = KEY_ASCIITILDE;
	keys[kVK_ANSI_LeftBracket] = KEY_BRACKETLEFT;
	keys[kVK_ANSI_Backslash] = KEY_BACKSLASH;
	keys[kVK_ANSI_RightBracket] = KEY_BRACKETRIGHT;
	keys[kVK_ANSI_Quote] = KEY_QUOTEDBL;
	keys[kVK_ANSI_Equal] = KEY_PLUS;
	keys[kVK_ANSI_Comma] = KEY_COMMA;
	keys[kVK_ANSI_Minus] = KEY_MINUS;
	keys[kVK_ANSI_Period] = KEY_PERIOD;

	for (auto const &[key, value] : keys) {
		pressed[value] = false;
	}

	// Mouse buttons, special handler for these from the mice fd
	pressed[MOUSE_BUTTON_LEFT] = false;
	pressed[MOUSE_BUTTON_MIDDLE] = false;
	pressed[MOUSE_BUTTON_RIGHT] = false;
	pressed[MOUSE_BUTTON_XBUTTON1] = false;
	pressed[MOUSE_BUTTON_XBUTTON2] = false;
}

BackgroundInputCapture::~BackgroundInputCapture() {
	// Add your cleanup here.
}

void BackgroundInputCapture::_process(double delta) {
	bool has_changed = false;

	for (auto const &[key, value] : keys) {
		if (CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, key)) {
			if (!pressed.get(value, false)) {
				pressed[value] = true;
				has_changed = true;
			}
		} else if (pressed.get(value, false)) {
			pressed[value] = false;
			has_changed = true;
		}
	}

	// Handle the mouse buttons separately
	if (CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState, kCGMouseButtonLeft)) {
		if (!pressed[MOUSE_BUTTON_LEFT]) {
			pressed[MOUSE_BUTTON_LEFT] = true;
			has_changed = true;
		}
	} else if (pressed[MOUSE_BUTTON_LEFT]) {
		pressed[MOUSE_BUTTON_LEFT] = false;
		has_changed = true;
	}

	if (CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState, kCGMouseButtonCenter)) {
		if (!pressed[MOUSE_BUTTON_MIDDLE]) {
			pressed[MOUSE_BUTTON_MIDDLE] = true;
			has_changed = true;
		}
	} else if (pressed[MOUSE_BUTTON_MIDDLE]) {
		pressed[MOUSE_BUTTON_MIDDLE] = false;
		has_changed = true;
	}

	if (CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState, kCGMouseButtonRight)) {
		if (!pressed[MOUSE_BUTTON_RIGHT]) {
			pressed[MOUSE_BUTTON_RIGHT] = true;
			has_changed = true;
		}
	} else if (pressed[MOUSE_BUTTON_RIGHT]) {
		pressed[MOUSE_BUTTON_RIGHT] = false;
		has_changed = true;
	}

	if (has_changed) {
		emit_signal("bg_key_pressed", this, pressed);
	}
}
