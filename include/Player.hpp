#pragma once
#include "Entity.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player : public Entity {
public:
  Player(Vector2f p_pos, SDL_Texture *p_texture);
  void move();
  void setCamera();

  Vector2f pos;
  Vector2f vel;
  double gravityForce;
  SDL_Rect currentFrame;
  SDL_Rect collisionBody;
  SDL_Texture *texture;
};
