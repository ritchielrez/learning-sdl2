#pragma once

#include "Entity.hpp"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <type_traits>
#include <vector>

struct Manager
{
  private:
    std::vector<std::unique_ptr<Entity>> entities;

  public:
    // Remove the dead entities
    void refresh()
    {
        // Using iterators, <https://www.geeksforgeeks.org/iterators-c-stl/>
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                      [](const std::unique_ptr<Entity> &mEntity) { return !mEntity->alive; }),
                       std::end(entities));
    }
    void update(double dt)
    {
        for (auto &e : entities)
            e->update(dt);
    }
    void render()
    {
        for (auto &e : entities)
            e->render();
    }
    Entity &addEntity()
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        Entity *e = entity.get();
        entities.emplace_back(std::move(entity));

        // We want a reference to the entity object to return.
        // Returning the pointer to it won't work, becuase the pointer
        // points to an heap allocated object. You can reference to a
        // heap allocatd object, but you have to dereference the pointer
        // and make a reference.
        return *e;
    }
};
