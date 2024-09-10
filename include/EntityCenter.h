#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <unordered_map>
#include "Render.h"
#include "TransformComponent.h"

class EntityCenter {
public:
  size_t entity_count = 0;
  std::unique_ptr<Render> render_system;


  EntityCenter();
  ~EntityCenter();

  uint32_t createEntity();
  void deleteEntity(uint32_t eID);
  void makeSystems(const char *obj);
  void run();
  
  std::unordered_map<uint32_t, TransformComponent> transformComponents;

private:

  uint32_t current_entity = 0;
  std::vector<uint32_t> free_space;

  bool contains(uint32_t eID);
  
};
