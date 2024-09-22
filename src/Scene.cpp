#include "Scene.h"
#include "EntityCenter.h"
#include <glm/common.hpp>
#include <memory>

Scene::Scene() : camera{glm::vec3{0.0f, 0.0, 10.0}, 0, 0} {
  eCenter = std::make_unique<EntityCenter>();
}

void Scene::buildTerrain() {
  for (int i = -renderDistance; i < renderDistance; i++) {
    terrain.push_back(buildChunk(i, 0));
  }
}

Chunk Scene::buildChunk(float x, float y) {
  return Chunk(CSize, x, y, *eCenter);
}

void Scene::movePlayer(float x, float y) {
  camera.move(x, y);
  int chuckPos = (camera.pos.x / CSize);

  if(liveEdge >= renderDistance)
  {
    buildChunk(renderDistance, 0);
    buildChunk(renderDistance + 1, 0);
    buildChunk(renderDistance + 2, 0);
    buildChunk(renderDistance + 3, 0);
    renderDistance = liveEdge + 4;
  }

    std::cout << liveEdge << "::" << renderDistance << std::endl;

  liveEdge = chuckPos + 4;

}
