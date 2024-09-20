#include "Camera.h"
#include "EntityCenter.h"
#include "window.h"
#include <GLFW/glfw3.h>
#include <memory>

std::unique_ptr<nWindow> window;
std::unique_ptr<EntityCenter> eCenter(new EntityCenter());

void renderLoop();
void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods);
void mouseMoveCallback(GLFWwindow *window, double xpos, double ypos);
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);

Camera camera{glm::vec3{0.0, 0.0, -0.5}, 0, 0};

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

  uint32_t entity = eCenter->createEntity();
  TransformComponent transform;
  transform.pos = glm::vec3{0, 0, 0};
  eCenter->transformComponents[entity] = transform;


  entity = eCenter->createEntity();
  transform.pos = glm::vec3{1, 0, 0};
  eCenter->transformComponents[entity] = transform;

  eCenter->makeSystems(camera);
  window->run();
  return 0;
}

bool forward, back, left, right;
double now; 
double delta;
double lastTime;

void handleMove() {
  float speed = 1.0 * delta;

  if (forward) {
    camera.move(0.0, speed);
  }
  if (back) {
    camera.move(0.0, -speed);
  }
  if (left) {
    camera.move(-speed, 0.0);
  }
  if (right) {
    camera.move(speed, 0.0);
  }
}


void renderLoop() {
  now = glfwGetTime();
  delta = now - lastTime;
  lastTime = now;

  handleMove();
  camera.update();
  eCenter->render();
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

  if (action == GLFW_RELEASE) {
    switch (key) {
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

  camera.look(xoffset / 10.0f, yoffset / 10.0f);
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
}

void scrollCallback(GLFWwindow *window, double xoffset, double yoffset) {}
