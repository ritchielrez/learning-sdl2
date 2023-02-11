#include "Game.hpp"
#include "Math.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

Map::Map(SDL_Texture *texture) {
  for (int x = 0, i = 0; i <= TILES_TOTAL; x += TILE_WIDTH, ++i) {
    std::cout << "Tile " << i << "\n";
    tiles.push_back(Tile(Vector2f(x, 150), texture));
  }
}

void Map::update() {
    srand(time(NULL));

    int status;

    for(size_t i = 0; i <= TILES_TOTAL; ++i) {
        status = rand() % 2;
        switch(status) {
        case 2:
            tiles.erase(tiles.begin() + i);
            break;
        default:
            break;
        }        
    }
}