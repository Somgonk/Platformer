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

vector<string> levels {
  "../levels/1.lf",
  "../levels/2.lf",
  "../levels/3.lf",
  "../levels/4.lf",
  "../levels/5.lf"
};

int main() {
  Window window;
  View view;

  Layer layer1;
  Layer layer2;
  Layer playerLayer;

  view.AddLayer(layer1);
  view.AddLayer(layer2);
  view.AddLayer(playerLayer);

  int levelNumber = 0;

  Level *level = new Level(levels.at(levelNumber));
  level->SetLayer(&layer2);

  Player player(level);
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
      player.ChangeVelocity({-0.5, 0});
    }
    if (window.keyStates[GLFW_KEY_D]) {
      player.ChangeVelocity({0.5, 0});
    }
    if (window.keyStates[GLFW_KEY_W]) {
      if (player.onGround) {
        player.ChangeVelocity({0, 12});
      }
    }


    player.UpdateVelocity(deltaTime);
    player.UpdatePosition(deltaTime);

    if (player.nextLevel) {
      levelNumber++;
      if (levelNumber < levels.size()) {
        level = new Level(levels.at(levelNumber)); 
        level->SetLayer(&layer2);
        player.SetLevel(level);
        player.nextLevel = false;
      } else {
        cout << "You win!!" << endl;
      }
    }

    // Update graphics
    view.Submit();
    
    bgfx::frame();

  }
  bgfx::shutdown();
	glfwTerminate();

  return 0;
}
