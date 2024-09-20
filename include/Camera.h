#pragma once

#include <glm/fwd.hpp>
#include <glm/vec3.hpp>   // glm::vec3
#include <glm/vec4.hpp>   // glm::vec4
#include <glm/mat4x4.hpp>

class Camera{
public:

  glm::vec3 pos;
  glm::vec3 forwards;
  glm::vec3 right;
  glm::mat4 look_model;
  double theta;
  double phi;

  Camera();
  Camera(glm::vec3, double theta, double phi);
  ~Camera();

  void move(float x, float y);
  void look(float, float);
  void update();
  glm::mat4 getView();

private:
  float scalar = 1.0f;
};
