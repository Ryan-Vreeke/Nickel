#include "EntityCenter.h"

#include <GLFW/glfw3.h>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <thread>

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
  movement_system = std::make_unique<MovementSystem>();
}

void EntityCenter::move(uint32_t entity, float x, float y, float speed) {
  movementComponents[entity].dir = {x, 0.0f, y};
  movementComponents[entity].speed = speed * deltaTime;
  movement_system->moveEntities(entity, movementComponents);
}

void EntityCenter::render() {
  now = glfwGetTime();
  deltaTime = now - lastTime;
  lastTime = now;

  render_system->update(positionComponents);
}

void EntityCenter::run() {
  std::thread thread([&]() -> void {
    while (1) {
      movement_system -> update(movementComponents, positionComponents);
      std::this_thread::sleep_for(std::chrono::milliseconds(17));
    }
  });
  thread.detach();
}
