extends Label

func _on_background_input_capture_bg_key_pressed(node, key_pressed):
	var s: String = ""
	
	for i in key_pressed:
		s += " " + OS.get_keycode_string(i) if !OS.get_keycode_string(i).strip_edges().is_empty() else str(i)

	self.text = s
