#include "window.h"

void Window::glfw_errorCallback(int error, const char *description) {
  cout << "Uh oh! It's a glfw error!\n" << description << endl;
}

void Window::glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  cout << "Key pressed: " << key << endl;
}

void Window::glfw_resizeCallback(GLFWwindow *window, int width, int height) {
  cout << "Resize occured:\n Width: " << width << "\n Height: " << height << endl;
  int oldWidth = width;
  int oldHeight = height;
  glfwGetWindowSize(window, &width, &height);
  if (width != oldWidth || height != oldHeight) {
    bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
    bgfx::setViewRect(view, 0, 0, bgfx::BackbufferRatio::Equal);
  }
}



Window::Window() {
  // inits glfw
  if (!glfwInit()) {
    fail = 1;
    return;
  }
  glfwSetErrorCallback(glfw_errorCallback);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  window = glfwCreateWindow(1024, 768, "Platformer", nullptr, nullptr);

  glfwSetKeyCallback(window, glfw_keyCallback);
  glfwSetWindowSizeCallback(window, glfw_resizeCallback);

  // Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
  bgfx::renderFrame();
  bgfx::Init bgfxInit;

  //Platform specific config
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	bgfxInit.platformData.ndt = glfwGetX11Display();
	bgfxInit.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	bgfxInit.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	bgfxInit.platformData.nwh = glfwGetWin32Window(window);
#endif

  glfwGetWindowSize(window, &width, &height);
  
  bgfxInit.resolution.width = (uint32_t)width;
  bgfxInit.resolution.height = (uint32_t)height;
  bgfxInit.resolution.reset = BGFX_RESET_VSYNC;

  if (!bgfx::init(bgfxInit)) {
    fail = 1;
    return;
  }
  
  bgfx::setViewClear(view, BGFX_CLEAR_COLOR);
  bgfx::setViewRect(view, 0, 0, bgfx::BackbufferRatio::Equal);

}



