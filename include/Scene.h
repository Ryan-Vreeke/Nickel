#pragma once

#include "EntityManager.h"

class Scene {
public:
  std::vector<uint32_t> entities;
  Scene();

private:
  EntityManager em;
};
