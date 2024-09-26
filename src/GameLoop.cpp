#include "GameRender.h"
#include "Controller.h"
#include "Scene.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include <ratio>

using namespace std::chrono_literals;

nWindow *window;
Scene scene;

static float deltaTime;

// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

void create_window() {
  window = new nWindow(1000, 1000);
  window->init_window();

  window->keyCallback(Controller::keyCallback);
  window->mousePassiveCallback(Controller::mouseMoveCallback);
  window->scrollCallback(Controller::scrollCallback);
  window->mouseActiveCallback(Controller::mouseButtonCallback);
}

bool handleEvents() {
  if(Controller::commands.size() < 1)
    return false;

  int key = Controller::commands.top();
  if (key == GLFW_KEY_ESCAPE) {
    Controller::commands.pop();
    window->close();
    return true;
  }
  return false;
}

void update() {}

void render() {
  scene.render();
  window->swap();
}

int main() {
  using clock = std::chrono::high_resolution_clock;
  create_window();

  std::chrono::nanoseconds lag(0ns);
  auto time_start = clock::now();
  bool quit_game = false;

  scene.buildScene();
  scene.fillChunk();

  while (!quit_game) {
    window->windowEvents();
    auto delta_time = clock::now() - time_start;
    time_start = clock::now();
    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
    deltaTime = std::chrono::duration<float, std::milli>(delta_time).count();

    quit_game = handleEvents();

    // update game logic as lag permits
    while (lag >= timestep) {
      lag -= timestep;

      update(); // update at a fixed rate each time
    }

    render();
  }
}
