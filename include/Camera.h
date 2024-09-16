#pragma once

#include <glm/fwd.hpp>
#include <glm/vec3.hpp>   // glm::vec3
#include <glm/vec4.hpp>   // glm::vec4

class Camera{
public:

  glm::vec3 pos;
  glm::vec3 target;
  glm::vec3 up;

  Camera();
  ~Camera();

  void move(glm::vec3);
  void look(float, float);
  glm::mat4 getView();

private:
  float scalar = 1.0f;
};
