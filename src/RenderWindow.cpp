#include "Game.hpp"
#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

RenderWindow::RenderWindow(const char *title, int width, int height)
    : window(NULL), renderer(NULL) {
  window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width, height, SDL_WINDOW_SHOWN);

  if (window == NULL)
    std::cout << "Window failed to init, Error: " << SDL_GetError() << "\n";

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath) {
  SDL_Texture *texture = NULL;
  texture = IMG_LoadTexture(renderer, filePath);

  if (texture == NULL)
    std::cout << "Texture failed to load, Error: " << SDL_GetError() << "\n";

  return texture;
}

void RenderWindow::clear() {
  SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
  SDL_RenderClear(renderer);
}

void RenderWindow::render(Player &player, int frame, int scale) {
  SDL_Rect src;
  src.x = player.currentFrame.x * (frame / PLAYER_FRAME_DELAYED);
  src.y = player.currentFrame.y;
  src.w = player.currentFrame.w;
  src.h = player.currentFrame.h;

  SDL_Rect dst;
  dst.x = player.pos.x * scale;
  dst.y = player.pos.y * scale;
  dst.w = src.w * scale;
  dst.h = src.h * scale;

  SDL_RenderCopy(renderer, player.texture, &src, &dst);
}
void RenderWindow::render(Player &player, int scale) {
  SDL_Rect src;
  src.x = player.currentFrame.x;
  src.y = player.currentFrame.y;
  src.w = player.currentFrame.w;
  src.h = player.currentFrame.h;

  SDL_Rect dst;
  dst.x = player.pos.x * scale;
  dst.y = player.pos.y * scale;
  dst.w = src.w * scale;
  dst.h = src.h * scale;

  SDL_RenderCopy(renderer, player.texture, &src, &dst);
}
void RenderWindow::render(Tile &tile, int scale) {
  SDL_Rect src;
  src.x = tile.tile.x * scale;
  src.y = tile.tile.y * scale;
  src.w = tile.tile.w * scale;
  src.h = tile.tile.h * scale;

  SDL_Rect dst;
  dst.x = tile.pos.x * scale;
  dst.y = tile.pos.y * scale;
  dst.w = src.w;
  dst.h = src.h;

  SDL_RenderCopy(renderer, tile.texture, &src, &dst);
}
void RenderWindow::render(Vector2f pos, SDL_Texture *texture, int scale) {
  SDL_Rect src;
  src.x = 0;
  src.y = 0;
  SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

  SDL_Rect dst;
  dst.x = pos.x * scale;
  dst.y = pos.y * scale;
  dst.w = src.w * scale;
  dst.h = src.h * scale;

  SDL_RenderCopy(renderer, texture, &src, &dst);
}
void RenderWindow::render(Entity &entity, int scale) {
  SDL_Rect src;
  src.x = entity.currentFrame.x;
  src.y = entity.currentFrame.y;
  src.w = entity.currentFrame.w;
  src.h = entity.currentFrame.h;

  SDL_Rect dst;
  dst.x = entity.pos.x * scale;
  dst.y = entity.pos.y * scale;
  dst.w = src.w * scale;
  dst.h = src.h * scale;

  SDL_RenderCopy(renderer, entity.texture, &src, &dst);
}
void RenderWindow::render(Entity &entity) {
  SDL_Rect src;
  src.x = entity.currentFrame.x;
  src.y = entity.currentFrame.y;
  SDL_QueryTexture(entity.texture, NULL, NULL, &src.w, &src.h);

  SDL_Rect dst;
  dst.x = entity.pos.x;
  dst.y = entity.pos.y;
  dst.w = src.w;
  dst.h = src.h;

  SDL_RenderCopy(renderer, entity.texture, &src, &dst);
}
void RenderWindow::display() { SDL_RenderPresent(renderer); }

int RenderWindow::getRefreshRate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;

  SDL_GetDisplayMode(displayIndex, 0, &mode);

  return mode.refresh_rate;
}

bool RenderWindow::checkCollision(Player &a, Tile &b, int scale) {
  SDL_Rect rectA;
  rectA.x = (a.pos.x + a.collisionBody.x) * scale;
  rectA.y = (a.pos.y + a.collisionBody.y) * scale;
  rectA.w = a.collisionBody.w * scale;
  rectA.h = a.collisionBody.h * scale;

  SDL_Rect rectB;
  rectB.x = b.pos.x * scale;
  rectB.y = b.pos.y * scale;
  rectB.w = b.tile.w * scale;
  rectB.h = b.tile.h * scale;

  if(SDL_HasIntersection(&rectA, &rectB)) {
    return true;
  }

  return false;
}


RenderWindow::~RenderWindow() { SDL_DestroyWindow(window); }