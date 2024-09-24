#include "EntityManager.h"
#include <algorithm>

EntityManager::EntityManager() {}

uint32_t EntityManager::createEntity() {
  entity_count++;
  if (free_space.size() == 0)
    return current_entity++;

  uint32_t eID = free_space.back();
  free_space.pop_back();

  return eID;
}

void EntityManager::deleteEntity(uint32_t eID) {
  if (std::find(free_space.begin(), free_space.end(), eID) != free_space.end())
    return;
  free_space.push_back(eID);
  entity_count--;
}

void EntityManager::deleteEntities(std::vector<uint32_t> eID) {
  for(auto entity : eID){
    deleteEntity(entity);
  }
}

void deleteEntity(Entity e){
  deleteEntity(e.m_id);
}

void deleteEntities(std::vector<Entity> entities){
  for(auto e : entities){
    deleteEntity(e.m_id);
  }
}

void EntityManager::makeSystems() {}
