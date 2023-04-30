#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

#include "Component.hpp"

#include <cstdint>

class PositionComponent : public Component
{
  public:
    uint32_t x, y;

    PositionComponent(uint32_t pX, uint32_t pY) : x(pX), y(pY)
    {
    }
};
