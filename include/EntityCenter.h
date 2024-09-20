#pragma once

#include "Camera.h"
#include "Render.h"
#include "Components.h"
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

class EntityCenter {
public:
  size_t entity_count = 0;
  std::unique_ptr<Render> render_system;

  EntityCenter();
  ~EntityCenter();

  uint32_t createEntity();
  void deleteEntity(uint32_t eID);
  void makeSystems(Camera &camera);
  void render();

  std::unordered_map<uint32_t, TransformComponent> transformComponents;

private:
  uint32_t current_entity = 0;
  std::vector<uint32_t> free_space;

  bool contains(uint32_t eID);
};
