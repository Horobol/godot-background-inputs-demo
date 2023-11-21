# Sample Background Hotkeys

**Warning:** This serves as a proof of concept to get key states while Godot is not in focus. All operating system implementations simply listen for the F1-F12 keys and emit a signal if pressed.

## Prerequisites

If you are looking to build the GDExtension yourself you will need to follow the [prerequisites page on the Godot documenation](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html) 

- **Note:** You can technically use the .dll/.exp/.lib/.so/.framework files inside the HotkeyTest and setup gdextensions like I have in the `HotkeyTest/bin` directory. This should work provided you are using `4.1.2-stable` release of Godot. This technically can work for later versions, though Godot may change the implementation of GDExtensions as it is still in development.

## Building

Provided you followed the steps in the Godot documentation (particularly fetching the godot-cpp repository and building it with scons). Simply running `scons platform=[platform]` in the root directory will build the GDExtension libraries and drop them into the HotkeyTest `bin` directory for use in that project. Eligible platforms are: `windows`, `macos`, `linux`

## Files

### godot-cpp

This is the C++ bindings repository for Godot's GDExtensions. I should make this a proper submodule later but you can find an appropriate version for the Godot version you are on [here](https://github.com/godotengine/godot-cpp). This sample project was compiled against the `4.1.2-stable` tag. Again, only really necessary if you want to build the GDExtension yourself.

### HotkeyTest

This folder contains a tiny Godot project that utilizes the GDExtension in this project. It consists of a main scene that contains a `Label` and a custom `BackgroundInputCapture` node defined in the GDExtension. The `BackgroundInputCapture` node emits a signal for the F1-F12 keys and the `Label` node simply sets the text to whatever key is pushed.

- **Note:** For the GDExtension to be used in the sample project. A gdextension file detailing libraries needs to be defined along with the libraries themselves. This can be found within the `bin` folder inside the HotkeyTest Godot project.

### src

This folder contains the C++ code that implements the custom Node. Platform dependant code will behave differently for each operating system but will ultimately result in input being captured regardless of whether the Godot window is in focus or not. Each OS has a slightly different approach:

#### Windows

- Simply uses the `GetAsyncKeyState` method to check the state of the keys in the map on a given frame. For this demo I have mapped out the F1-F12 keys. [Check the Microsoft Docs for more information on GetAsyncKeyState](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate)

#### MacOS

- Similar to the Windows implementation, this uses the `CGEventSourceKeyState` method to check the state of the keys in the map on a given frame. F1-F12 keys are mapped. [Check the Apple Docs for more information on CGEventSourceKeyState](https://developer.apple.com/documentation/coregraphics/1408768-cgeventsourcekeystate)

#### Linux

- This one is slightly more interesting as there is no official API for this. A file descriptor is opened that will attempt to read incoming events from the keyboard input device and read an event per frame. The program makes an attempt at figuring out the keyboard input device, if not found then the node will not emit any signals. A good amount of code for detecting the input device has been lifted from [logkeys - GNU/Linux Keylogger](https://github.com/kernc/logkeys/tree/master). The F1-F12 keys are mapped.
