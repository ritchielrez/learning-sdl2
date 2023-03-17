#include "Tile.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Tile::Tile(Vector2f p_pos, SDL_Texture *p_texture) : pos(p_pos), texture(p_texture)
{
    tile.x = 0;
    tile.y = 0;
    tile.w = TILE_WIDTH;
    tile.h = TILE_HEIGHT;
}
