#include "Game.hpp"
#include "GameObject.hpp"
#include <iostream>
#include <memory>

void Game::init(const char* title, uint32_t width, uint32_t height) {
    if (SDL_Init(SDL_INIT_VIDEO > 0)) {
        std::cout << "SDL failed to init, Error: " << SDL_GetError << "\n";
        return;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "SDL_Image failed to init, Error: " << SDL_GetError << "\n";
    }

	mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (!mWindow) {
		std::cout << "Window failed to init, Error: " << SDL_GetError << "\n";
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!mRenderer) {
		std::cout << "Renderer failed to init, Error: " << SDL_GetError << "\n";
		return;
	}

	grass = std::make_unique<GameObject>(loadTexture("res/gfx/ground_grass_1.png"), 0, 0, mRenderer);

	gameLoop();
}

void Game::gameLoop() {
	while (gameRunning) {
		handleEvents();
		update();
		render();
	}
}

void Game::handleEvents() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameRunning = false;
			break;
		}
	}
}

SDL_Texture* Game::loadTexture(const char* filepath) {
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(mRenderer, filepath);

	if (!texture) {
		std::cout << "This texture " << filepath << " failed to load, Error: " << SDL_GetError() << "\n";
	}

	return texture;
}

void Game::render() {

	SDL_SetRenderDrawColor(mRenderer, 135, 206, 235, 255);
	SDL_RenderClear(mRenderer);

	grass->render();

	SDL_RenderPresent(mRenderer);
}

void Game::update() {
	grass->update();
}

Game::~Game() {
	SDL_Quit();
}
