#include "Components.h"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <unordered_map>
#include <vector>

class MovementSystem {
public:
  MovementSystem();

  void update(std::unordered_map<uint32_t, MovementComponent> &movement,
              std::unordered_map<uint32_t, PositionComponent> &posComp);

  void moveEntities(uint32_t entity, std::unordered_map<uint32_t, MovementComponent> &movement);

private:
  std::vector<uint32_t> movingEntities;
};
