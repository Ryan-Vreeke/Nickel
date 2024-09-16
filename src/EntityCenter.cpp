#include "EntityCenter.h"

#include <algorithm>
#include <iostream>
#include <memory>

EntityCenter::EntityCenter() {}

EntityCenter::~EntityCenter() {}

uint32_t EntityCenter::createEntity() {
  entity_count++;
  if (free_space.size() == 0)
    return current_entity++;

  uint32_t eID = free_space.back();
  free_space.pop_back();

  return eID;
}

void EntityCenter::deleteEntity(uint32_t eID) {
  if (std::find(free_space.begin(), free_space.end(), eID) != free_space.end())
    return;
  free_space.push_back(eID);
  entity_count--;
}

void EntityCenter::makeSystems(Camera &camera) {
  render_system = std::make_unique<Render>(camera);
}

void EntityCenter::run() { render_system->update(transformComponents); }
