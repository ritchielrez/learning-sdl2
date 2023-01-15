#include "Entity.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(Vector2f p_pos, SDL_Texture *p_texture)
    : pos(p_pos), texture(p_texture) {
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = 32;
  currentFrame.h = 32;
}
