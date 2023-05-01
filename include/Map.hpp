#pragma once

#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"

#include "ECS/RenderComponent.hpp"

#include "Game.hpp"
#include "Vector2D.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdint>
#include <vector>

const uint32_t tilesTotal = 11;
const uint32_t tileWidth = 32;
const uint32_t tileHeight = 32;

struct Map
{
    Map();
    Map(const char *texturePath);
    void init(const char *texturePath);
    void update();

    SDL_Texture *mTexture;
    Entity *grass[tilesTotal];
};
