#pragma once
#include "Math.hpp"
#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Map {
public:
    Map(SDL_Texture *texture);
    void update();

    std::vector<Tile> tiles;
    std::vector<Tile> tilesCollidedList;
};