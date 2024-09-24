#pragma once

#include <cstdint>
class Entity {
public:
  bool m_alive;
  uint32_t m_id;

  Entity(uint32_t _id);
};
