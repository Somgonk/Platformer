#include <iostream>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/embedded_shader.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm/vec2.hpp>

#include "window.h"
#include "rendering.h"

using namespace std;

vector<ColorVertex> v1 {
  {-0.5f, -0.5f, 0xffffffff},
  {0.5f, -0.5f, 0xffffffff},
  {0.0f, 0.5f, 0xffffffff},
  {1.0f, 0.0f, 0x00fffff}
};
vector<uint16_t> i1 {
  0, 1, 2,
  3, 2, 1
};
vector<ColorVertex> v2 {
  {-1.0f, 1.0f, 0xff00ff00},
  {-1.0f, 0.0f, 0x00ff00ff},
  {0.0f, 0.0f, 0x0f0f0f0f}
};
vector<uint16_t> i2 {
  0, 1, 2
};


int main() {
  Window window;
  View view;
  Layer layer1(window, v1, i1);
  Layer layer2(window, v2, i2);
  view.AddLayer(layer1);
  view.AddLayer(layer2);
  while (!glfwWindowShouldClose(window.window)) {
		glfwPollEvents();
        // Update game
    if (window.keyStates[GLFW_KEY_A]) {
      v1.at(0).x_pos -= 0.01;
    }
    if (window.keyStates[GLFW_KEY_D]) {
      v1.at(0).x_pos += 0.01;
    }
    layer1.UpdateVertexBuffer(v1);
    // Update graphics
    view.Submit();
    
    bgfx::frame();

  }
  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
