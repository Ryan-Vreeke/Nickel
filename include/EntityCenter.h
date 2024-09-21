#pragma once

#include "Render.h"
#include "Camera.h"
#include "Components.h"
#include "MovementSystem.h"
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

class EntityCenter {
public:
  float now;
  float deltaTime;
  float lastTime;

  size_t entity_count = 0;
  std::unique_ptr<Render> render_system;
  std::unique_ptr<MovementSystem> movement_system;

  EntityCenter();
  ~EntityCenter();

  uint32_t createEntity();
  void deleteEntity(uint32_t eID);
  void makeSystems(Camera &camera);
  void render();
  void run();
  void move(uint32_t entity, float x, float y, float speed);

  std::unordered_map<uint32_t, PositionComponent> positionComponents;
  std::unordered_map<uint32_t, MovementComponent> movementComponents;

private:
  uint32_t current_entity = 0;
  std::vector<uint32_t> free_space;

  bool contains(uint32_t eID);
};
