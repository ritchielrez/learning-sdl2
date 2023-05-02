#include "Entity.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "RenderWindow.hpp"
#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <chrono>

using ChronoTime = std::chrono::high_resolution_clock::time_point;

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
  Map map(grassTexture);

  bool gameRunning = true;
  SDL_Event event;
  int frame = 0;

  ChronoTime currentTime = std::chrono::high_resolution_clock::now();

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        gameRunning = false;
        break;
      }
    }

    window.clear();

    for (Tile &tile : map.tiles) {
       if(window.checkCollision(player, tile, PLAYER_SCALE, ENTITY_SCALE)) { 
         map.tilesCollidedList.push_back(tile);
       }
      window.render(tile, ENTITY_SCALE);
    }

    window.render(player, frame, PLAYER_SCALE);

    window.display();

    player.move();
    ++frame;
    if(map.tilesCollidedList.size() > 0) {
       player.move();
       ++frame;
     }
     else {
       player.pos.y += player.gravityForce;
     } 

    map.tilesCollidedList.clear();
    map.update();

    ChronoTime newTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = newTime - currentTime;

    double frameTime = std::chrono::duration<double>(elapsedTime).count();

    std::cout << "Frame Time: " << frameTime << "\n";
    std::cout << "Current FPS: " << 1.0f / frameTime << "\n";

    currentTime = newTime;

    if (frame / PLAYER_FRAME_DELAYED >= PLAYER_FRAMES) {
      frame = 0;
    }
  }

  SDL_Quit();

  return 0;
}
