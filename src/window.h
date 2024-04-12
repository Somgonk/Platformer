#ifndef WINDOW_H_HEADER_GUARD
#define WINDOW_H_HEADER_GUARD

#include <iostream>

#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#include <bitset>

#if BX_PLATFORM_LINUX
  #define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
  #define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
  #define GLFW_EXPOSE_NATIVE_COCOA
#endif

#include <GLFW/glfw3native.h>

using namespace std;
class Window {
  public:
    Window();
    int fail;

    // glfw variables
    GLFWwindow *window;
    int width;
    int height;
    
    static bool keyStates[GLFW_KEY_LAST + 1]; 

  private:
    static void glfw_errorCallback(int error, const char *description);
    static void glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void glfw_resizeCallback(GLFWwindow *window, int width, int height);
  };

#endif
