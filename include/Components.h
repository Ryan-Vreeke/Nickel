#pragma once

#include <glm/ext.hpp>

struct PositionComponent {
  glm::vec3 pos;
  glm::vec3 scale;
};

struct MovementComponent{
  glm::vec3 dir;
  float speed;
};


