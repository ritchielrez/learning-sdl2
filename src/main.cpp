#include "Entity.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include "Player.hpp"
#include "RenderWindow.hpp"
#include "Tile.hpp"
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
  std::vector<Tile> tiles;
  std::vector<Tile> tilesCollidedList;

  for (int x = 0; x <= 300; x += TILE_WIDTH) {
    tiles.push_back(Tile(Vector2f(x, 150), grassTexture));
  }

  bool gameRunning = true;
  bool playerOnGround = false;
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

    for (Tile &tile : tiles) {
      if(window.checkCollision(player, tile, ENTITY_SCALE)) { 
        tilesCollidedList.push_back(tile);
      }
      window.render(tile, ENTITY_SCALE);
    }

    window.render(player, frame, ENTITY_SCALE);

    window.display();

    if(tilesCollidedList.size() > 0) playerOnGround = true;
    else { playerOnGround = false; }

    if(playerOnGround) {
      player.move();
      ++frame;
    }
    else {
      if(player.pos.x + player.currentFrame.w >= SCREEN_WIDTH / ENTITY_SCALE) {
        player.pos.x = -40;
      }
      else {
        player.pos.y += player.gravityForce;
      }
    }

    tilesCollidedList.clear();

    if (frame / PLAYER_FRAME_DELAYED >= PLAYER_FRAMES) {
      frame = 0;
    }
  }

  SDL_Quit();

  return 0;
}
