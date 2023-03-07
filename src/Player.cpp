#include "Entity.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Player::Player(Vector2f p_pos, SDL_Texture *p_texture)
    : Entity(p_pos, p_texture){
  pos = p_pos;
  texture = p_texture;

  gravityForce = 5;

  vel.x = 1;
  vel.y = gravityForce * 1.5;

  // Note: this x position is of 2nd frame of the player, don't change it.
  // Check the RenderWindow::render() to learn how the player gets rendered
  currentFrame.x = 64;
  currentFrame.y = 0;
  currentFrame.w = 64;
  currentFrame.h = 64;

  // These x and y coordinates are offsets to the player's actual x and y position
  collisionBody.x = 18;
  collisionBody.y = 2;
  collisionBody.w = currentFrame.w - 32;
  collisionBody.h = currentFrame.h - 16;
}

void Player::move() {
  pos.x += vel.x;
}

void Player::setCamera() {
  #if DEBUG
  Game::camera.x = pos.x - SCREEN_WIDTH / 2;
  Game::camera.y = pos.y - SCREEN_HEIGHT / 2;

  if (Game::camera.x < 0)
    Game::camera.x = 0;
  if (Game::camera.y < 0)
    Game::camera.y = 0;
  if (Game::camera.x > Game::camera.w)
    Game::camera.x = Game::camera.w;
  
  std::cout << "Camera x: " << Game::camera.x << "\n";
  std::cout << "Camera x: " << Game::camera.x << "\n";
  #endif
}