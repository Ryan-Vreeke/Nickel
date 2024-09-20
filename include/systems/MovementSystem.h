#include <cstdint>
#include <unordered_map>
#include "Components.h"

class MovementSystem{
public:
  MovementSystem();

  void update(std::unordered_map<uint32_t, MovementComponent> &movementComp,std::unordered_map<uint32_t, TransformComponent> &transformComponent);

};
