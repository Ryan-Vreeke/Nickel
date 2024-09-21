#include "Scene.h"
#include "EntityCenter.h"
#include <memory>

Scene::Scene() : camera{glm::vec3{0.0f, 0.0, 10.0}, 0, 0} {
  eCenter = std::make_unique<EntityCenter>();
}

void Scene::buildTerrain() {
  /*for (int i = -1; i < 2; i++) {*/
  /*  for (int j = -1; j < 2; j++) {*/
  /*    terrain.push_back(buildChunk(i, j));*/
  /*  }*/
  /*}*/

  terrain.push_back(buildChunk(-1, -1));
  terrain.push_back(buildChunk(1, 1));
  terrain.push_back(buildChunk(0, 0));
}

Chunk Scene::buildChunk(float x, float y) {

  return Chunk(CSize, x, y, *eCenter);
}
