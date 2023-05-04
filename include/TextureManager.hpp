#pragma once

#include "Game.hpp"

class TextureManager
{
  public:
    static SDL_Texture *load(const char *fileName);
    static void render(SDL_Texture *texture, SDL_Rect src, SDL_FRect dst);
};
