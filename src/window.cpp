#include "window.h"

#include <GL/freeglut_std.h>

nWindow::nWindow() {
  width = 800;
  height = 800;
}

nWindow::nWindow(unsigned int _width, unsigned int _height)
    : width(_width), height(_height) {}

nWindow::~nWindow() {}

void nWindow::init_window(int *argc, char *argv[]) {
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(width, height);

  window = glutCreateWindow("Vox Game");
  glewInit();
}

void nWindow::run() { glutMainLoop(); }

void nWindow::set_display(void (*func)()) { glutDisplayFunc(func); }

void nWindow::idle(void (*func)()) { glutIdleFunc(func); }

void nWindow::key_interrupt(void (*func)(int, int, int)) {
  glutSpecialFunc(func);
}

void nWindow::mousePassive(void (*func)(int x, int y)) {
  glutPassiveMotionFunc(func);
}

void nWindow::activeMouse(void (*func)(int button, int state, int x, int y)) {
  glutMouseFunc(func);
}
