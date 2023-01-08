#include "Entity.hpp"
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

  SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

  Entity platform0(100, 50, grassTexture);

  bool gameRunning = true;

  SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        gameRunning = false;
    }
    window.clear();
    window.render(platform0);
    window.display();
  }

  SDL_Quit();

  return 0;
}
