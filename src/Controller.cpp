#include "Controller.h"
#include <iostream>

std::stack<int> Controller::commands;

Controller::Controller() {}

void Controller::mousePassive(int x, int y) {}

void Controller::keyCallback(GLFWwindow *window, int key, int scancode,
                             int action, int mods) {

  if (action == GLFW_PRESS) {
    commands.push(key);
  }
}

void Controller::mouseMoveCallback(GLFWwindow *window, double xpos,
                                   double ypos) {}

void Controller::mouseButtonCallback(GLFWwindow *window, int button, int action,
                                     int mods) {}

void Controller::scrollCallback(GLFWwindow *window, double xoffset,
                                double yoffset) {}
