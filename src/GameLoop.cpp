
#include "GameRender.h"
#include "Controller.h"
#include <chrono>
#include <ratio>

using namespace std::chrono_literals;

nWindow *window;
static float deltaTime;

// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

struct game_state {
  // this contains the state of your game, such as positions and velocities
};

bool handle_events() {
  // poll for events

  return false; // true if the user wants to quit the game
}

void update(game_state *) { // update game logic here
}

void render(game_state const &) { window->swap(); }

game_state interpolate(game_state const &current, game_state const &previous, float alpha) {
  game_state interpolated_state;

  // interpolate between previous and current by alpha here

  return interpolated_state;
}

void create_window() {
  window = new nWindow(1000, 1000);
  window->init_window();

  window->keyCallback(Controller::keyCallback);
  window->mousePassiveCallback(Controller::mouseMoveCallback);
  window->scrollCallback(Controller::scrollCallback);
  window->mouseActiveCallback(Controller::mouseButtonCallback);
}

int main() {
  using clock = std::chrono::high_resolution_clock;

  std::chrono::nanoseconds lag(0ns);
  auto time_start = clock::now();
  bool quit_game = false;

  game_state current_state;
  game_state previous_state;

  while (!quit_game) {
    auto delta_time = clock::now() - time_start;
    time_start = clock::now();
    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
    /*deltaTime = std::chrono::duration<float, std::milli>(delta_time).count();*/

    quit_game = handle_events();

    // update game logic as lag permits
    while (lag >= timestep) {
      lag -= timestep;

      previous_state = current_state;
      update(&current_state); // update at a fixed rate each time
    }

    // calculate how close or far we are from the next timestep
    auto alpha = (float)lag.count() / timestep.count();
    auto interpolated_state = interpolate(current_state, previous_state, alpha);

    render(interpolated_state);
    window->windowEvents();
  }
}
