#include "Map.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"

#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"
#include "ECS/RenderComponent.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdint>
#include <cmath>
#include <vector>

Map::Map()
{
}

Map::Map(const char *texturePath)
{
    init(texturePath);
}

void Map::init(const char *texturePath)
{
    for (uint32_t i = 0; i < tilesTotal; ++i)
    {
        grass[i] = &Game::sManager.addEntity();
        grass[i]->addComponent<RenderComponent>(texturePath, Vector2D(i * tileWidth, 150), 4);
    }
}

void Map::update(double timeStep)
{
    for (uint32_t i = 0; i < tilesTotal; ++i)
    {
        grass[i]->getComponent<RenderComponent>().mPos.x -= round(60 * timeStep);
        if (grass[i]->getComponent<RenderComponent>().mPos.x + tileWidth  <= 0)
        {
            grass[i]->getComponent<RenderComponent>().mPos.x = round(tileWidth * (tilesTotal - 1) - 60 * timeStep);
        }
    }
}
