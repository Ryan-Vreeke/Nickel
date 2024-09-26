#pragma once

#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>

class nWindow {
public:
  unsigned int width;
  unsigned int height;
  bool open;

  nWindow();
  nWindow(unsigned int _width, unsigned int _height);
  ~nWindow();

  int init_window();
  void swap();
  void windowEvents();
  void mousePassiveCallback(void (*passive)(GLFWwindow *, double, double));
  void mouseActiveCallback(void (*cb)(GLFWwindow *, int, int, int));
  void scrollCallback(void (*cb)(GLFWwindow *, double, double));
  void keyCallback(void (*cb)(GLFWwindow *, int, int, int, int));
  void close();

private:
  GLFWwindow *window;

};
