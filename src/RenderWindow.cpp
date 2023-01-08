#include "RenderWindow.hpp"
#include "SDL2/SDL_render.h"
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

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath) {
  SDL_Texture *texture = NULL;
  texture = IMG_LoadTexture(renderer, filePath);

  if (texture == NULL)
    std::cout << "Texture failed to load, Error: " << SDL_GetError() << "\n";

  return texture;
}

void RenderWindow::clear() { SDL_RenderClear(renderer); }

void RenderWindow::render(SDL_Texture *texture) {
  SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::display() { SDL_RenderPresent(renderer); }

RenderWindow::~RenderWindow() { SDL_DestroyWindow(window); }
