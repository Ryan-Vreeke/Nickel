#pragma once

#include "EntityCenter.h"
#include <cstdint>
#include <vector>

class Chunk {
public:
  std::vector<uint32_t> blocks; // 16*16

  Chunk(uint16_t size, int offsetX, int offsetY, EntityCenter &ec);
};
