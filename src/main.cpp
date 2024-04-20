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
#include "player.h"

using namespace std;

int main() {
  Window window;
  View view;

  Layer layer1;
  Layer layer2;
  Layer playerLayer;

  view.AddLayer(layer1);
  view.AddLayer(layer2);
  view.AddLayer(playerLayer);

  Level level("../levels/test.lf");
  level.SetLayer(&layer2);

  Player player(0.2);
  player.SetLayer(&playerLayer);

  double lastTime = glfwGetTime();
  while (!glfwWindowShouldClose(window.window)) {
    //Calculate Deltatime
    double currentTime = glfwGetTime();
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;


		glfwPollEvents();
    window.HandleResize();
    // Update game
    if (window.keyStates[GLFW_KEY_A]) {
      player.ChangeVelocity({0.1, 0});
    }
    if (window.keyStates[GLFW_KEY_D]) {
      player.ChangeVelocity({-0.1, 0});
    }
    player.UpdateVelocity(deltaTime);
    player.UpdatePosition(deltaTime);
    // Update graphics
    view.Submit();
    
    bgfx::frame();

  }
  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
