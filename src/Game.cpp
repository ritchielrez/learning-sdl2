#include "Game.hpp"
#include <iostream>
#include <memory>

void SDLDelete::operator()(SDL_Window* window)
{
	SDL_DestroyWindow(window);
}

void SDLDelete::operator()(SDL_Renderer* window)
{
	SDL_DestroyRenderer(window);
}

void SDLDelete::operator()(SDL_Texture* window)
{
	SDL_DestroyTexture(window);
}

void Game::init(const char* title, uint32_t width, uint32_t height) {
    if (SDL_Init(SDL_INIT_VIDEO > 0)) {
        std::cout << "SDL failed to init, Error: " << SDL_GetError << "\n";
        return;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "SDL_Image failed to init, Error: " << SDL_GetError << "\n";
    }

	mWindow = std::unique_ptr<SDL_Window, SDLDelete>
		(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));

	if (!mWindow) {
		std::cout << "Window failed to init, Error: " << SDL_GetError << "\n";
		return;
	}

	mRenderer = std::unique_ptr<SDL_Renderer, SDLDelete>
		(SDL_CreateRenderer(mWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

	if (!mRenderer) {
		std::cout << "Renderer failed to init, Error: " << SDL_GetError << "\n";
		return;
	}

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

std::unique_ptr<SDL_Texture, SDLDelete> Game::loadTexture(const char* filepath) {
	std::unique_ptr<SDL_Texture, SDLDelete> texture = NULL;
	texture = std::unique_ptr<SDL_Texture, SDLDelete>
		(IMG_LoadTexture(mRenderer.get(), filepath));

	if (!texture) {
		std::cout << "This texture " << filepath << " failed to load, Error: " << SDL_GetError() << "\n";
	}

	return texture;
}

void Game::render() {
	std::unique_ptr<SDL_Texture, SDLDelete> grassTexture = loadTexture("res/gfx/ground_grass_1.png");

	SDL_SetRenderDrawColor(mRenderer.get(), 135, 206, 235, 255);
	SDL_RenderClear(mRenderer.get());
	SDL_RenderCopy(mRenderer.get(), grassTexture.get(), NULL, NULL);
	SDL_RenderPresent(mRenderer.get());
}

void Game::update() {

}

Game::~Game() {
	SDL_Quit();
}
