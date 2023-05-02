#include "Game.hpp"
#include "Map.hpp"
#include "Vector2D.hpp"

#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Manager.hpp"

#include "ECS/RenderComponent.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <chrono>
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

void Game::gameLoop()
{
    const double ftStep = 1.0, ftSlice = 1.0;

    ChronoTime currentTime = std::chrono::high_resolution_clock::now();

    double lastFrameTime = 0.0, currentSlice = 0.0;

    while (gameRunning)
    {
        handleEvents();

        sManager.refresh();

        currentSlice += lastFrameTime;

        for (; currentSlice >= ftSlice; currentSlice -= ftSlice)
        {
            update(ftSlice);
        }

        render();

        ChronoTime newTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = newTime - currentTime;

        double frameTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(elapsedTime).count();
        double frameTimeInSecs = std::chrono::duration<double>(elapsedTime).count();

        std::cout << "Frame time: " << frameTimeInSecs << "\n";

        lastFrameTime = frameTime;

        std::cout << "Current FPS: " << 1.0f / frameTimeInSecs << "\n";

        currentTime = newTime;
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

void Game::update(double timeStep)
{
    map.update(timeStep);
    sManager.update(timeStep);
}

Game::~Game()
{
    SDL_Quit();
}
