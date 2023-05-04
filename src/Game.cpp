#include "Game.hpp"
#include "Map.hpp"
#include "Math.hpp"
#include "Vector2D.hpp"

#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"

#include "ECS/RenderComponent.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>

using ChronoTime = std::chrono::high_resolution_clock::time_point;

Manager Game::sManager;
SDL_Renderer *Game::sRenderer{NULL};

Map map;

void Game::init(const char *title, uint32_t width, uint32_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL failed to init, Error: " << SDL_GetError << "\n";
        return;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "SDL_Image failed to init, Error: " << SDL_GetError << "\n";
    }

    mWindow =
        SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (!mWindow)
    {
        std::cout << "Window failed to init, Error: " << SDL_GetError << "\n";
        return;
    }

    sRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!sRenderer)
    {
        std::cout << "Renderer failed to init, Error: " << SDL_GetError << "\n";
        return;
    }

    map.init("res/gfx/ground_grass_1.png");

    gameLoop();
}

// TODO: Make this gameloop work well on other frame rates
void Game::gameLoop()
{
    double frameTime = 0.0;
    float frameTimeInSecs = 0.0;

    const int capFPS = 60;
    const int capFrameTime = 1000 / capFPS;

    int countedFrames = 0;

    while (gameRunning)
    {
        int delayFrameTime = 0;
        ChronoTime startTime = std::chrono::high_resolution_clock::now();

        handleEvents();

        sManager.refresh();

        update(1.0f / capFPS);

        render();

        ChronoTime endTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = endTime - startTime;

        frameTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(elapsedTime).count();
        frameTimeInSecs = Math::roundToFloat(std::chrono::duration<double>(elapsedTime).count());

        std::cout << "[INFO] Frame time(in ms): " << frameTime << "\n";

        if (frameTime < capFrameTime)
        {
            delayFrameTime = capFrameTime - frameTime;
            SDL_Delay(delayFrameTime);
        }

        std::cout << "[INFO] Delay frame time(in ms): " << delayFrameTime << "\n";

        frameTime += delayFrameTime;
        double fps = 1000.0f / frameTime;

        std::cout << "[INFO] Current FPS: " << round(fps) << "\n";

        std::cout << "[INFO] Frame " << ++countedFrames << " finished\n";
    }
}

void Game::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;
        }
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(sRenderer, 135, 206, 235, 255);
    SDL_RenderClear(sRenderer);

    sManager.render();

    SDL_RenderPresent(sRenderer);
}

void Game::update(double deltaTime)
{
    map.update(deltaTime);
    sManager.update(deltaTime);
}

Game::~Game()
{
    SDL_Quit();
}
