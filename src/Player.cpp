#include "Player.hpp"
#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Player::Player(Vector2f p_pos, SDL_Texture *p_texture)
    : Entity(p_pos, p_texture){
  pos = p_pos;
  texture = p_texture;
  currentFrame[0].x = 0;
  currentFrame[0].y = 0;
  currentFrame[0].w = 60;
  currentFrame[0].h = 64;

  currentFrame[1].x = 64;
  currentFrame[1].y = currentFrame[0].y;
  currentFrame[1].w = currentFrame[0].w;
  currentFrame[1].h = currentFrame[0].h;

  currentFrame[2].x = 128;
  currentFrame[2].y = currentFrame[0].y;
  currentFrame[2].w = currentFrame[0].w;
  currentFrame[2].h = currentFrame[0].h;
  
  currentFrame[3].x = 192;
  currentFrame[3].y = currentFrame[0].y;
  currentFrame[3].w = currentFrame[0].w;
  currentFrame[3].h = currentFrame[0].h; 
}