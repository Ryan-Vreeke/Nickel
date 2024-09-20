#include "Camera.h"
#include <algorithm>
#include <cmath>
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>

Camera::Camera() : pos(0.0f, 0.0f, 5.0f), theta(0), phi(0) {}

Camera::Camera(glm::vec3 position, double theta, double phi)
    : pos(position), theta(theta), phi(phi) {}

Camera::~Camera() {}

void Camera::move(float x, float y) {
  pos += (right * x);
  pos += (forwards * y);
}

void Camera::look(float lookX, float lookY) {
  theta -= lookX;
  theta = std::fmod(theta, 360.0);
  phi = std::min(89.0, std::max(-89.0, (phi + lookY)));
}

void Camera::update() {
  glm::vec3 up;
  glm::vec3 target;

  forwards = {glm::cos(glm::radians(theta)) * glm::cos(glm::radians(phi)),
              glm::sin(glm::radians(theta)) * glm::cos(glm::radians(phi)),
              glm::sin(glm::radians(phi))};

  right = glm::cross(forwards, {0.0f, 0.0f, 1.0f});
  up = glm::cross(right, forwards);

  target = pos + forwards;
  look_model = glm::lookAt(pos, target, up);
}

glm::mat4 Camera::getView() { return look_model; }
