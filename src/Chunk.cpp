#include "Chunk.h"
#include "EntityCenter.h"
#include <cstdint>

Chunk::Chunk(uint16_t size, int offsetX, int offsetY, EntityCenter &ec) {

  uint32_t entity;
  PositionComponent pc;
  int adjusted = size / 2;

  for (int i = -adjusted; i < adjusted; i++) {
    for (int j = -adjusted; j < adjusted; j++) {
      entity = ec.createEntity();

      pc.pos = glm::vec3{i + offsetX * size, j + offsetY * size, 0};
      pc.scale = glm::vec3{1.0f};
      ec.positionComponents[entity] = pc;

      blocks.push_back(entity);
    }
  }
}
