#pragma once
#include "Entity.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Platform : public Entity {
public:
  Platform(Vector2f p_pos, SDL_Texture *p_texture);
  Vector2f pos;
  SDL_Rect currentFrame;
  SDL_Texture *texture;
};
