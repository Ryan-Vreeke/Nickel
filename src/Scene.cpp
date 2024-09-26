#include "Scene.h"
#include "Components.h"
#include <glm/fwd.hpp>

Scene::Scene() {}

void Scene::buildScene() {
  camera = em.createEntity();
  CCamera cc{0, 0, glm::mat4{0}};
  CTransform ct;
  ct.pos = glm::vec3{-5.0, 0, 5.0};
  em.camera_entities[camera] = cc;
  em.t_entities[camera] = ct;

  em.makeSystems();
}

void Scene::fillChunk() {
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      auto e = em.createEntity();
      CTransform t = {glm::vec3(i, j, 0)};
      em.t_entities[e] = t;
      entities.push_back(e);
    }
  }
}

void Scene::render() {
  em.camera_system.makeLookMat(em.camera_entities, em.t_entities, camera);
  em.render_system.render(em.t_entities, em.camera_entities[camera], entities);
}
