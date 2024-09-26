#pragma once

#include "EntityManager.h"
#include <cstdint>

class Scene {
public:
  uint32_t camera;
  std::vector<uint32_t> entities;
  uint32_t chunk[32][32];

  Scene();

  void fillChunk();
  void render();
  void buildScene();

private:
  EntityManager em;
};
