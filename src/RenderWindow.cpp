#include "RenderWindow.hpp"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
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

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath) {
  SDL_Texture *texture = NULL;
  texture = IMG_LoadTexture(renderer, filePath);

  if (texture == NULL)
    std::cout << "Texture failed to load, Error: " << SDL_GetError() << "\n";

  return texture;
}

void RenderWindow::clear() { SDL_RenderClear(renderer); }

void RenderWindow::render(Entity &entity, int scale) {
  SDL_Rect src;
  src.x = entity.currentFrame.x;
  src.y = entity.currentFrame.y;
  SDL_QueryTexture(entity.texture, NULL, NULL, &src.w, &src.h);

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

RenderWindow::~RenderWindow() { SDL_DestroyWindow(window); }
