#include "Player.hpp"
#include "Entity.hpp"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Player::Player(Vector2f p_pos, SDL_Texture *p_texture)
    : Entity(p_pos, p_texture) {
  pos = p_pos;
  texture = p_texture;
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = 52;
  currentFrame.h = 52;
}
