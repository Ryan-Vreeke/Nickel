#include "Controller.h"

Controller::Controller() {}

void Controller::mousePassive(int x, int y) {}

void Controller::keyCallback(GLFWwindow *window, int key, int scancode,
                             int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  if (action == GLFW_PRESS) {
  }

  if (action == GLFW_RELEASE) {
  }
}

void Controller::mouseMoveCallback(GLFWwindow *window, double xpos,
                                   double ypos) {
  /*if (firstMouse) {*/
  /*  lastX = xpos;*/
  /*  lastY = ypos;*/
  /*  firstMouse = false;*/
  /*}*/
  /**/
  /*float xoffset = xpos - lastX;*/
  /*float yoffset = lastY - ypos;*/
  /**/
  /*lastX = xpos;*/
  /*lastY = ypos;*/
  /**/
  /*scene.camera.look(xoffset * scene.eCenter->deltaTime * 10,*/
  /*                  yoffset * scene.eCenter->deltaTime * 10);*/
}

void Controller::mouseButtonCallback(GLFWwindow *window, int button, int action,
                                     int mods) {}

void Controller::scrollCallback(GLFWwindow *window, double xoffset,
                                double yoffset) {}
