#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "Utils.hpp"
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

  std::vector<Entity> platform;

  for(int x = 0; x <= 300; x += 30) {
    platform.push_back(Entity(Vector2f(x, 150), grassTexture));
  }

  bool gameRunning = true;

  SDL_Event event;

  const float timeStep = 0.01f;
  float accumlator = 0.0f;
  float currentTime = utils::hireTimeInSeconds();

  while (gameRunning) {
    int startTicks = SDL_GetTicks();
    float newTime = utils::hireTimeInSeconds();
    float frameTime = newTime - currentTime;

    currentTime = newTime;
    accumlator += currentTime;

    while (accumlator >= timeStep) {
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
          gameRunning = false;
      }

      accumlator -= timeStep;
    }
    const float alpha = accumlator / timeStep;

    window.clear();

    for (Entity &entity : platform) {
      window.render(entity);
    }

    window.display();

    int frameTicks = SDL_GetTicks() - startTicks;

    if(frameTicks < 1000 / window.getRefreshRate()) {
        SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
    }
  }

  SDL_Quit();

  return 0;
}
