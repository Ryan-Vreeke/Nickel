#pragma once

#include <glm/ext.hpp>

struct TransformComponent {
  glm::vec3 pos;
};

struct MovementComponent{
  glm::vec3 dir;
  float speed;
};

