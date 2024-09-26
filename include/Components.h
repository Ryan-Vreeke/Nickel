#pragma once

#include <glm/ext.hpp>
#include <glm/ext/vector_float3.hpp>

struct CTransform {
  glm::vec3 pos;
  glm::vec3 forwards;
  glm::vec3 up;
};

struct CCamera{
  double theta;
  double phi;
  glm::mat4 look_model;
};
