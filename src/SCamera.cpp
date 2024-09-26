#include "SCamera.h"
#include "Components.h"
#include <cstdint>
#include <glm/fwd.hpp>
#include <unordered_map>

SCamera::SCamera() {}
void SCamera::makeLookMat(std::unordered_map<uint32_t, CCamera> &ccamera,
                          std::unordered_map<uint32_t, CTransform> &ctransform,
                          uint32_t camera) {
  CCamera &cc = ccamera[camera];
  CTransform &ct = ctransform[camera];

  glm::vec3 target;

  ct.forwards = {
      glm::cos(glm::radians(cc.theta)) * glm::cos(glm::radians(cc.phi)),
      glm::sin(glm::radians(cc.theta)) * glm::cos(glm::radians(cc.phi)),
      glm::sin(glm::radians(cc.phi))};

  glm::vec3 right = glm::cross(ct.forwards, {0.0f, 0.0f, 1.0f});
  ct.up = glm::cross(right, ct.forwards);

  target = ct.pos + ct.forwards;
  cc.look_model = glm::lookAt(ct.pos, target, ct.up);
}
