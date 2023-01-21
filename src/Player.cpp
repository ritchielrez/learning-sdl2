#include "Player.hpp"
#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Player::Player(Vector2f p_pos, SDL_Texture *p_texture)
    : Entity(p_pos, p_texture){
  pos = p_pos;
  texture = p_texture;

  // Note: this x position is of 2nd frame of the player, don't change it.
  // Check the RenderWindow::render() to learn how the player gets rendered
  currentFrame.x = 64;
  currentFrame.y = 0;
  currentFrame.w = 64;
  currentFrame.h = 64;
}