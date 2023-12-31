#ifndef BACKGROUNDINPUTCAPTURE_H
#define BACKGROUNDINPUTCAPTURE_H

#include <map>
#include <string>
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class BackgroundInputCapture : public Sprite2D {
	GDCLASS(BackgroundInputCapture, Sprite2D)

private:
	std::map<int, std::string> keys;
	int fd;

protected:
	static void _bind_methods();

public:
	BackgroundInputCapture();
	~BackgroundInputCapture();

	void _process(double delta);
};

}

#endif
