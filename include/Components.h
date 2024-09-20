#pragma once

#include <glm/ext.hpp>

struct TransformComponent {
  glm::vec3 pos;
};

struct CameraComponent {
  glm::vec3 pos;
  double theta;
  double phi;
  glm::vec3 right;
  glm::vec3 target;
  glm::vec3 forward;
  glm::vec3 up;
};
