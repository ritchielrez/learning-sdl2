#include "Game.hpp"
#include "Math.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

Map::Map(SDL_Texture *texture) {
  reset(texture);
}

void Map::reset(SDL_Texture *texture) {
#if DEBUG
  std::cout << "Tiles total: " << TILES_TOTAL << "\n";
#endif
  for (int i = 0; i < TILES_TOTAL; ++i) {
    tiles.push_back(Tile(Vector2f(i * TILE_WIDTH, 150), texture));
#if DEBUG
    std::cout << "Tile number: " << i <<  " x: " << tiles[i].pos.x << "\n";
#endif
  }
}

void Map::update() {
  for(int i = 0; i < TILES_TOTAL; ++i) {
    tiles[i].pos.x -= 1;
    if(tiles[i].pos.x + TILE_WIDTH <= 0) {
      tiles[i].pos.x = TILE_WIDTH * (TILES_TOTAL - 1) - 1;
    }
#if DEBUG
    std::cout << "Tile number: " << i <<  " x: " << tiles[i].pos.x << "\n";
#endif
  }
#if DEBUG
  std::cout << "\n";
#endif
}