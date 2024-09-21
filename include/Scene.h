#pragma once

#include "Chunk.h"
#include <algorithm>
#include <vector>
#include "EntityCenter.h"

class Scene {
public:
  static const int CSize = 16;
  Camera camera;

  std::unique_ptr<EntityCenter> eCenter;

  Scene();
  void buildTerrain();
  void run();

private:
  std::vector<Chunk> terrain;

  Chunk buildChunk(float x, float y);
};
