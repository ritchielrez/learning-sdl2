#pragma once

#include "ECS/Manager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// TODO: unused constants
#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 720

#define ENTITY_SCALE 4
#define PLAYER_SCALE 3

#define PLAYER_FRAMES 4
#define PLAYER_FRAME_DELAYED 8

#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define TILES_TOTAL 11

#define DEBUG 0

class Game
{
  public:
    const uint32_t windowWidth = 1280;
    const uint32_t windowHeight = 720;
    bool gameRunning = true;
    SDL_Event event;

    static Manager sManager;

    ~Game();

    static SDL_Renderer *getRenderer() noexcept
    {
        return sRenderer;
    };

    void init(const char *title, uint32_t width, uint32_t height);
    void gameLoop();
    void handleEvents();
    void render();
    void update(double deltaTime);

  private:
    SDL_Window *mWindow = NULL;
    static SDL_Renderer *sRenderer;
};
