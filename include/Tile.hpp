#pragma once
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Tile
{
  public:
    Tile(Vector2f p_pos, SDL_Texture *p_texture);

    Vector2f pos;
    SDL_Rect tile;
    SDL_Texture *texture;
    int status;
};
