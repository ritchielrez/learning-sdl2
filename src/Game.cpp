#include "Game.hpp"
#include <iostream>
#include <memory>

Game::Game()
	: mWindow(NULL, SDL_DestroyWindow), mRenderer(NULL, SDL_DestroyRenderer) {
}

int Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO > 0)) {
        std::cout << "SDL failed to init, Error: " << SDL_GetError << "\n";
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "SDL_Image failed to init, Error: " << SDL_GetError << "\n";
    }

	mWindow = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow);

	if (!mWindow) {
		std::cout << "Window failed to init, Error: " << SDL_GetError << "\n";
		return 1;
	}

	mRenderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(SDL_CreateRenderer(mWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);

	if (!mRenderer) {
		std::cout << "Renderer failed to init, Error: " << SDL_GetError << "\n";
		return 1;
	}
	 
	gameLoop();
}

void Game::gameLoop() {
	bool gameRunning = true;
	SDL_Event event;

	while(gameRunning) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gameRunning = false;
				break;
			}
		}
	}
}

Game::~Game() {
	SDL_Quit();
}
