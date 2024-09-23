#include "Camera.h"
#include "EntityCenter.h"
#include "Scene.h"
#include "window.h"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <glm/fwd.hpp>
#include <memory>

std::unique_ptr<nWindow> window;

void renderLoop();
void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods);
void mouseMoveCallback(GLFWwindow *window, double xpos, double ypos);
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);

uint32_t entity;

Scene scene;
double lastX = 0;
double lastY = 0;
bool firstMouse = true;

int main(int argc, char *argv[]) {
  window = std::make_unique<nWindow>(1000, 1000);
  window->init_window(&argc, argv);

  window->idle(renderLoop);
  window->keyCallback(keyCallback);
  window->mousePassiveCallback(mouseMoveCallback);
  window->scrollCallback(scrollCallback);
  window->mouseActiveCallback(mouseButtonCallback);

  scene.eCenter->makeSystems(scene.camera);
  scene.eCenter->run();

  scene.buildTerrain();
  window->run();
  return 0;
}

bool forward, back, left, right, obj_right;

void handleMove() {
  float speed = 10.0 * scene.eCenter->deltaTime;
  if (forward) {
    scene.movePlayer(0.0, speed);
  }
  if (back) {
    scene.movePlayer(0.0, -speed);
  }
  if (left) {
    scene.movePlayer(-speed, 0.0);
  }
  if (right) {
    scene.movePlayer(speed, 0.0);
  }
}

void renderLoop() {
  handleMove();
  scene.camera.update();
  scene.eCenter->render();
}

void mousePassive(int x, int y) {}

void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  if (action == GLFW_PRESS) {
    switch (key) {
    case GLFW_KEY_W:
      forward = true;
      break;
    case GLFW_KEY_S:
      back = true;
      break;
    case GLFW_KEY_A:
      left = true;
      break;
    case GLFW_KEY_D:
      right = true;
      break;
    }
    return;
  }

  if (action == GLFW_RELEASE) { switch (key) {
    case GLFW_KEY_W:
      forward = false;
      break;
    case GLFW_KEY_S:
      back = false;
      break;
    case GLFW_KEY_A:
      left = false;
      break;
    case GLFW_KEY_D:
      right = false;
      break;
    }
  }
}

void mouseMoveCallback(GLFWwindow *window, double xpos, double ypos) {
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos;

  lastX = xpos;
  lastY = ypos;

  scene.camera.look(xoffset * scene.eCenter->deltaTime * 10,
                    yoffset * scene.eCenter->deltaTime * 10);
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
}

void scrollCallback(GLFWwindow *window, double xoffset, double yoffset) {}
