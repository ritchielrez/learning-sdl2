#pragma once

#include <cstdint>

struct Vector2D
{
    uint32_t x, y;

    Vector2D(uint32_t pX, uint32_t pY) : x(pX), y(pY)
    {
    }
};
