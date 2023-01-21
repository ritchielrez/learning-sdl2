#include "Entity.hpp"
#include "Game.h"
#include "Math.hpp"
#include "Player.hpp"
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

  RenderWindow window("Game v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

  SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
  SDL_Texture *playerTexture = window.loadTexture("res/gfx/hulking_knight.png");

  Player player(Vector2f(0, 0), playerTexture);
  std::vector<Entity> platform;

  for (int x = 0; x <= 300; x += 30) {
    platform.push_back(Entity(Vector2f(x, 150), grassTexture));
  }

  bool gameRunning = true;

  SDL_Event event;

  int frame = 0;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        gameRunning = false;
        break;
      }
    }

    window.clear();

    window.render(player, 4, frame);

    for (Entity &entity : platform) {
      window.render(entity, 4);
    }

    window.display();
    
    ++frame;
    if (frame / PLAYER_FRAME_DELAYED >= PLAYER_FRAMES) {
      frame = 0;
    }
  }

  SDL_Quit();

  return 0;
}
