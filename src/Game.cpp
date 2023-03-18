#include "Game.hpp"
#include "GameObject.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <chrono>
#include <iostream>
#include <memory>

using ChronoTime = std::chrono::high_resolution_clock::time_point;

SDL_Renderer *Game::sRenderer{NULL};

void Game::init(const char *title, uint32_t width, uint32_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO > 0))
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

    grass = std::make_unique<GameObject>("res/gfx/ground_grass_1.png", 0, 150);

    gameLoop();
}

void Game::gameLoop()
{
    double deltaTime = 0.01;
    double accumulator = 0.0;

    ChronoTime currentTime = std::chrono::high_resolution_clock::now();

    while (gameRunning)
    {
        handleEvents();

        ChronoTime newTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = newTime - currentTime;

        double frameTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(elapsedTime).count();

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= deltaTime)
        {
            update(deltaTime);
            accumulator -= deltaTime;
        }

        render();
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

    grass->render();

    SDL_RenderPresent(sRenderer);
}

void Game::update(double deltaTime)
{
    grass->update(deltaTime);
}

Game::~Game()
{
    SDL_Quit();
}
