# Sample Background Hotkeys

## Prerequisites

If you are looking to build the GDExtension yourself you will need to follow the [prerequisites page on the Godot documenation](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html) 

- **Note:** You can technically use the .dll file inside the HotkeyTest and setup gdextensions like I have in the `HotkeyTest/bin` directory. This should work provided you are using `4.1.2-stable` release of Godot. This technically can work for later versions, though Godot may change the implementation of GDExtensions as it is still in development.

## Files

### godot-cpp

This is the C++ bindings repository for Godot's GDExtensions. I should make this a proper submodule later but you can find an appropriate version for the Godot version you are on [here](https://github.com/godotengine/godot-cpp). This sample project was compiled against the `4.1.2-stable` tag. Again, only really necessary if you want to build the GDExtension yourself.

### HotkeyTest

This folder contains a tiny Godot project that utilizes the GDExtension in this project. It consists of a main scene that contains a `Label` and a custom `Win32InputCapture` node defined in the GDExtension. The `Win32InputCapture` node emits a signal for the F1-F12 keys and the `Label` node simply sets the text to whatever key is pushed.

- **Note:** For the GDExtension to be used in the sample project. A gdextension file detailing libraries needs to be defined along with the libraries themselves. This can be found within the `bin` folder inside the HotkeyTest Godot project.

### src

This folder contains the C++ code that implements the custom Node. At its core it simply uses the Windows `GetAsyncKeyState` method to listen for key events at that frame. Due to how its implemented this works for events while the application is unfocused, particularly useful for hotkeys. Additionally it sets up a signal and emits it.