extends Label

func _on_win_32_input_capture_bg_key_pressed(node, key_pressed):
	self.text = key_pressed
