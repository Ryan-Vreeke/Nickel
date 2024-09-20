#include "window.h"
#include <GLFW/glfw3.h>

nWindow::nWindow() {
  width = 800;
  height = 800;
}

nWindow::nWindow(unsigned int _width, unsigned int _height)
    : width(_width), height(_height) {}

nWindow::~nWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

int nWindow::init_window(int *argc, char *argv[]) {
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

  glfwWindowHint(GLFW_RED_BITS, 8); // Set RGBA color depth
  glfwWindowHint(GLFW_GREEN_BITS, 8);
  glfwWindowHint(GLFW_BLUE_BITS, 8);
  glfwWindowHint(GLFW_ALPHA_BITS, 8);
  glfwWindowHint(GLFW_DEPTH_BITS, 24); // Set depth buffer size

  window = glfwCreateWindow(width, height, "Nickel", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    return -1;
  }

  return 0;
}

void nWindow::run() {
  while (!glfwWindowShouldClose(window)) {
    idleCB();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void nWindow::idle(std::function<void()> func) { idleCB = func; }

void nWindow::mousePassiveCallback(void (*passive)(GLFWwindow *, double, double)) {
  glfwSetCursorPosCallback(window, passive);
}

void nWindow::mouseActiveCallback(void (*cb)(GLFWwindow *, int, int, int)) {
  glfwSetMouseButtonCallback(window, cb);
}

void nWindow::scrollCallback(void (*cb)(GLFWwindow *, double, double)) {
  glfwSetScrollCallback(window, cb);
}

void nWindow::keyCallback(void (*cb)(GLFWwindow *, int, int, int, int)) {
  glfwSetKeyCallback(window, cb);
}

