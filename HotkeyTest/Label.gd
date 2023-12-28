extends Label

func _on_background_input_capture_bg_key_pressed(node, keys_pressed):
	var s: String = ""
	
	for i in keys_pressed:
		if keys_pressed[i]:
			s += " " + OS.get_keycode_string(i) if !OS.get_keycode_string(i).strip_edges().is_empty() else " Keycode" + str(i)

	self.text = s
