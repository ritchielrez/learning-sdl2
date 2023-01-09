#include "Entity.hpp"
#include "RenderWindow.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO > 0))
    std::cout << "Hey, SDL_Init has failed, SDL_ERROR: " << SDL_GetError()
              << "\n";

  if (!IMG_Init(IMG_INIT_PNG))
    std::cout << "Hey, IMG_Init has failed, Error: " << SDL_GetError() << "\n";

  RenderWindow window("Game v1.0", 1280, 720);

  SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

  Entity entities[] = {
      Entity(0, 0, grassTexture),
      Entity(30, 0, grassTexture),
      Entity(30, 30, grassTexture),
      Entity(30, 60, grassTexture),
  };
  std::vector<Entity> entities_vect = {
      Entity(0, 0, grassTexture),
      Entity(30, 0, grassTexture),
      Entity(30, 30, grassTexture),
      Entity(30, 60, grassTexture),
  };

  bool gameRunning = true;

  SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        gameRunning = false;
    }
    window.clear();

    for(Entity &entity: entities_vect) {
        window.render(entity);
    }

    window.display();
  }

  SDL_Quit();

  return 0;
}
