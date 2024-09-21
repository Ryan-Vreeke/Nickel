#include "MovementSystem.h"
#include <GLFW/glfw3.h>
#include <cstdint>

MovementSystem::MovementSystem() {}

void MovementSystem::update(
    std::unordered_map<uint32_t, MovementComponent> &movement,
    std::unordered_map<uint32_t, PositionComponent> &posComp) {

  for (const auto &entity : movingEntities) {
    posComp[entity].pos += movement[entity].dir * movement[entity].speed;
  }
}

void MovementSystem::moveEntities( uint32_t entity, std::unordered_map<uint32_t, MovementComponent> &movement) {
  movingEntities.push_back(entity);
}
