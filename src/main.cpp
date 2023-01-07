#include "RenderWindow.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO > 0))
    std::cout << "Hey, SDL_Init has failed, SDL_ERROR: " << SDL_GetError()
              << "\n";

  if (!IMG_Init(IMG_INIT_PNG))
    std::cout << "Hey, IMG_Init has failed, Error: " << SDL_GetError() << "\n";

  RenderWindow window("Game v1.0", 1280, 720);

  bool gameRunning = true;

  SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        gameRunning = false;
    }
  }

  SDL_Quit();

  return 0;
}
