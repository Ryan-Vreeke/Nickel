#include <iostream>
#include <memory>
#include "EntityCenter.h"
#include "TransformComponent.h"
#include "window.h"

std::unique_ptr<nWindow> window;
std::unique_ptr<EntityCenter> eCenter(new EntityCenter());

void myDisplay();
void idle();
void myKeyboard(unsigned char key, int x, int y);
void myMouse(int button, int state, int x, int y);
void mousePassive(int x, int y);

int main(int argc, char *argv[])
{
	window = std::make_unique<nWindow>(800, 800);
	window->init_window(&argc, argv);
	window->set_display(myDisplay);
	window->key_interrupt(myKeyboard);
	window->mousePassive(mousePassive);
	window->activeMouse(myMouse);
	window->idle(idle);

  uint32_t entity = eCenter->createEntity();
	TransformComponent transform;
	transform.pos = glm::vec3{0, 0, 0};
  eCenter->transformComponents[entity] = transform;

  eCenter->makeSystems(argv[1]);
  eCenter->run();
  window->run();
	// Your program logic here
	return 0;
}

void myDisplay() {
  eCenter->run();
  glutSwapBuffers();
}

void idle() {
  // animations
  // redraw
  glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27://ESCAPE KEY
    glutLeaveMainLoop();
    break;
  }

  glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y) {}

void mousePassive(int x, int y) { 
  float fX = (x/(float)window->width) - 0.5f;
  float fy = (y/(float)window->height) - 0.5f;

  printf("x: %f, y: %f\n", fX, fy); 
}
