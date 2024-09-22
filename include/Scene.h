#pragma once

#include "Chunk.h"
#include <algorithm>
#include <vector>
#include "EntityCenter.h"

class Scene {
public:
  static const int CSize = 16;
  int renderDistance = 4;
  int liveEdge = 4;

  Camera camera;

  std::unique_ptr<EntityCenter> eCenter;

  Scene();
  void buildTerrain();
  void movePlayer(float x, float y);

private:
  std::vector<Chunk> terrain;

  Chunk buildChunk(float x, float y);
};
