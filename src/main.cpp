#include "Camera.h"
#include "EntityCenter.h"
#include "TransformComponent.h"
#include "window.h"
#include <GL/freeglut_std.h>
#include <iostream>
#include <memory>

std::unique_ptr<nWindow> window;
std::unique_ptr<EntityCenter> eCenter(new EntityCenter());

void myDisplay();
void idle();
void myKeyboard(int key, int x, int y);
void myMouse(int button, int state, int x, int y);
void mousePassive(int x, int y);

Camera camera;

int main(int argc, char *argv[]) {
  window = std::make_unique<nWindow>(1000, 1000);
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

  eCenter->makeSystems(camera);
  eCenter->run();
  window->run();
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

void myKeyboard(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_RIGHT: // ESCAPE KEY
    std::cout << "right " << camera.pos.z << std::endl;
    break;
  case GLUT_KEY_LEFT:
    glutWarpPointer(centerX, centerY);
    std::cout << "left" << std::endl;
    break;
  }

  glutPostRedisplay();
}

float lastX = 1.0f;
float lastY = 0;
bool firstMouse = true;

void myMouse(int button, int state, int x, int y) {}

void mousePassive(int x, int y) {
  if (firstMouse) {
    lastX = x;
    lastY = y;
    firstMouse = false;
  }

  float xoffset = lastX - x;

  lastX = x;
  lastY = y;

  camera.look(xoffset / 10.0f, 0.0f);

  glutPostRedisplay();
}
