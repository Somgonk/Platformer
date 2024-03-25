#include "screen.h"


static void glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
		s_showStats = !s_showStats;
}

Window::Window() {

  std::cout << "e";
}
