#pragma once

#include "Component.hpp"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>

constexpr std::size_t maxComponents = 32;
using ComponentArray = std::array<Component *, maxComponents>;
using ComponentBitset = std::bitset<maxComponents>;

class Entity
{
  private:
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitset componentBitset;

  public:
    bool alive = true;

    void update(double dt)
    {
        for (auto &c : components)
            c->update(dt);
    }

    void render()
    {
        for (auto &c : components)
            c->render();
    }

    template <typename T, typename... TArgs> T &addComponent(TArgs &&...mArgs)
    {
        T *c = new T(std::forward<TArgs>(mArgs)...);

        c->entity = this;

        std::unique_ptr<Component> component = std::unique_ptr<T>(c);
        components.emplace_back(std::move(component));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;

        c->init();

        return *c;
    }

    template <typename T> bool hasComponent()
    {
        return componentBitset[getComponentTypeID<T>()];
    }

    template <typename T> T &getComponent()
    {
        assert(hasComponent<T>());
        Component *component = componentArray[getComponentTypeID<T>()];
        return *static_cast<T *>(component);
    }
};
