#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>


struct Component;
class Entity;
struct Manager;

using ComponentID = std::size_t;

inline ComponentID getComponentID() noexcept
{
    static ComponentID lastID = 0u;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID;
}

struct Component
{
    Entity *entity;

    virtual void init()
    {
    }
    virtual void update(double dt)
    {
    }
    virtual void render()
    {
    }
};
