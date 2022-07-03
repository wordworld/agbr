# OpenGL

## [GLFW](https://www.glfw.org/)

GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop. It provides
a simple API for creating windows, contexts and surfaces, receiving input and events.

GLFW is written in C and supports Windows, macOS, X11 and Wayland.

## [GLEW](http://glew.sourceforge.net/)

The OpenGL Extension Wrangler Library (GLEW) is a cross-platform open-source C/C++ extension loading library. GLEW
provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform.
OpenGL core and extension functionality is exposed in a single header file. GLEW has been tested on a variety of
operating systems, including Windows, Linux, Mac OS X, FreeBSD, Irix, and Solaris.

* [GLFW3库在MacOS上导致 undefined symbol](https://www.coder.work/article/4061346)

  > Undefined symbols for architecture x86_64:
  >
  > "_CFArrayAppendValue", referenced from:
  >
  > _addJoystickElement in libglfw3.a(cocoa_joystick.o)
  >
  > ...

## 参考

[Mirosoft OpenGL Reference](https://docs.microsoft.com/zh-cn/windows/win32/opengl/opengl-reference)