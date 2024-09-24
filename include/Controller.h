#pragma once

#include <GLFW/glfw3.h>

class Controller {
public:
  Controller();

  static void mousePassive(int x, int y);
  static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void mouseMoveCallback(GLFWwindow *window, double xpos, double ypos);
  static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
  static void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);
};
