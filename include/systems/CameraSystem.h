#pragma once

#include "Components.h"
#include <glm/fwd.hpp>
class CameraSystem {
public:
  CameraSystem();
  glm::mat4 getView(CameraComponent &camera);
};
