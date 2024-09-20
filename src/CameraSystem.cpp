#include "CameraSystem.h"
#include "Components.h"

CameraSystem::CameraSystem() {}

glm::mat4 CameraSystem::getView(CameraComponent &camera) {
  camera.forward = glm::vec3{
      glm::cos(glm::radians(camera.theta)) * glm::cos(glm::radians(camera.phi)),
      glm::sin(glm::radians(camera.theta)) * glm::cos(glm::radians(camera.phi)),
      glm::sin(glm::radians(camera.phi))};

  camera.right = glm::cross(camera.forward, {0.0f, 0.0f, 1.0f});
  camera.up = glm::cross(camera.right, camera.forward);

  camera.target = camera.pos + camera.forward;
  return glm::lookAt(camera.pos, camera.target, camera.up);
}
