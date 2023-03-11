#include "Game.hpp"
#include <iostream>

int Game::init(const char* title, int width, int height) {
	mWindow = NULL; 
	mRenderer = NULL;

	mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (!mWindow) {
		std::cout << "Window failed to init, Error: " << SDL_GetError << "\n";
		return 1;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!mRenderer) {
		std::cout << "Rendere failed to init, Error: " << SDL_GetError << "\n";
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