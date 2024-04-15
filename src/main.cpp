#include <iostream>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/embedded_shader.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "window.h"
#include "rendering.h"
#include "level.h"

using namespace std;
vector<ColorVertex> v1 {
  {-0.5f, -0.5f, 0xffffffff},
  {0.5f, -0.5f, 0xffffffff},
  {0.5f, 0.5f, 0xffffffff},
  {-0.5f, 0.5f, 0x00fffff}
};
vector<uint16_t> i1 {
  0, 1, 2,
  2, 3, 0

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
  //Layer layer1(v1, i1, window.xScale, window.yScale);
  Layer layer1(v1, i1);

  //Layer layer2(v2, i2, window.xScale, window.yScale);

  view.AddLayer(layer1);
  //view.AddLayer(layer2);


  //Level level("../levels/test.lf");

  double lastTime = glfwGetTime();
  while (!glfwWindowShouldClose(window.window)) {
    //Calculate Deltatime
    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastTime;
    lastTime = currentTime;


		glfwPollEvents();
    window.HandleResize();
    // Update game
    if (window.keyStates[GLFW_KEY_A]) {
      v1.at(0).x_pos -= 0.1 * deltaTime;
      layer1.UpdateGeometry(v1);
    }
    if (window.keyStates[GLFW_KEY_D]) {
      v1.at(0).x_pos += 0.1 * deltaTime;
      layer1.UpdateGeometry(v1);

    }
        // Update graphics
    view.Submit();
    
    bgfx::frame();

  }
  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
