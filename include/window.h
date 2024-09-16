#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

class nWindow{
public:
  unsigned int width;
  unsigned int height;

  nWindow();
  nWindow(unsigned int _width, unsigned int _height);
  ~nWindow();

  void init_window(int *argc, char *argv[]);
  void run();
  void set_display(void (*func)());
  void idle(void (*func)());
  void key_interrupt(void (*func)(int, int, int));
  void mousePassive(void (*func) (int x, int y));
  void activeMouse(void (*func)(int button, int state, int x, int y));

private:
  int window;
};
