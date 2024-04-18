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

int main() {
  Window window;
  View view;

  Layer layer1;
  Layer layer2;

  view.AddLayer(layer1);
  view.AddLayer(layer2);

  Level level("../levels/test.lf");
  level.SetLayer(&layer2);


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
          }
    if (window.keyStates[GLFW_KEY_D]) {
      
    }
        // Update graphics
    view.Submit();
    
    bgfx::frame();

  }
  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
