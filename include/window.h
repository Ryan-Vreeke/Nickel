#pragma once

#include <functional>
#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

class nWindow {
public:
  unsigned int width;
  unsigned int height;

  nWindow();
  nWindow(unsigned int _width, unsigned int _height);
  ~nWindow();

  int init_window(int *argc, char *argv[]);
  void run();
  void idle(std::function<void()>);
  void mousePassiveCallback(void (*passive)(GLFWwindow *, double, double));
  void mouseActiveCallback(void (*cb)(GLFWwindow *, int, int, int));
  void scrollCallback(void (*cb)(GLFWwindow *, double, double));
  void keyCallback(void (*cb)(GLFWwindow *, int, int, int, int));

private:
  GLFWwindow *window;
  std::function<void()> idleCB;

};
