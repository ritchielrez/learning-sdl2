#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO > 0))
    std::cout << "Hey, SDL_Init has failed, SDL_ERROR: " << SDL_GetError()
              << "\n";

  if (!IMG_Init(IMG_INIT_PNG))
    std::cout << "Hey, IMG_Init has failed, Error: " << SDL_GetError() << "\n";

  return 0;
}
