#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Tile {
public:
    Tile(Vector2f p_pos, SDL_Texture *p_texture);
    void update();

    Vector2f pos;
    SDL_Rect tile;
    SDL_Texture *texture;
    int status;
};
