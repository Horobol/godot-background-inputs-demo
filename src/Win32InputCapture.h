#ifndef WIN32INPUTCAPTURE_H
#define WIN32INPUTCAPTURE_H

#include <map>
#include <string>
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class Win32InputCapture : public Sprite2D {
	GDCLASS(Win32InputCapture, Sprite2D)

private:
	std::map<int, std::string> keys;

protected:
	static void _bind_methods();

public:
	Win32InputCapture();
	~Win32InputCapture();

	void _process(double delta);
};

}

#endif