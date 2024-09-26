#pragma once

#include "Components.h"
#include "Entity.h"
#include "SRender.h"
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "SCamera.h"

class EntityManager {
public:
  size_t entity_count = 0;

  EntityManager();
  uint32_t createEntity();
  void deleteEntity(uint32_t eID);
  void deleteEntities(std::vector<uint32_t> eID);
  void deleteEntity(Entity);
  void deleteEntities(std::vector<Entity> entities);
  void makeSystems();

  std::unordered_map<uint32_t, CTransform> t_entities;
  std::unordered_map<uint32_t, CCamera> camera_entities;

  RenderSystem render_system;
  SCamera camera_system;
private:
  uint32_t current_entity = 0;
  std::vector<uint32_t> free_space;

};
