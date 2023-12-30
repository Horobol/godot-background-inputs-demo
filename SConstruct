#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])

if env["platform"] == "macos":
    env.Append(LINKFLAGS = ['-framework', 'Carbon'])
    sources = ["src/register_types.cpp", Glob("src/platform/macos/*.cpp")]
    library = env.SharedLibrary(
        "HotkeyTest/bin/libgdexample{}{}.framework/libgdexample{}{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "linux":
	sources = ["src/register_types.cpp", Glob("src/platform/linux/*.cpp")]
	library = env.SharedLibrary(
        "HotkeyTest/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
else:
    env.Append(LIBS = 'User32.lib')
    sources = ["src/register_types.cpp", Glob("src/platform/win32/*.cpp")]
    library = env.SharedLibrary(
        "HotkeyTest/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
