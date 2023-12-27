#ifndef BACKGROUNDINPUTCAPTURE_H
#define BACKGROUNDINPUTCAPTURE_H

#include <map>
#include <string>
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class BackgroundInputCapture : public Sprite2D {
	GDCLASS(BackgroundInputCapture, Sprite2D)

private:
	std::map<int, int> keys;
	Dictionary pressed;
	#ifdef __linux__
	int keyboardFd;
	int miceFd;
	#endif

protected:
	static void _bind_methods();

public:
	BackgroundInputCapture();
	~BackgroundInputCapture();

	void _process(double delta);
};

}

#endif
