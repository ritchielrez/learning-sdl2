#include "TextureManager.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

SDL_Texture *TextureManager::load(const char *fileName)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(Game::getRenderer(), fileName);

    if (!texture)
    {
        std::cout << "This texture " << fileName << " failed to load, Error: " << SDL_GetError() << "\n";
    }

    return texture;
}

void TextureManager::render(SDL_Texture *texture, SDL_Rect srcRect, SDL_FRect dstRect)
{
    SDL_RenderCopyF(Game::getRenderer(), texture, &srcRect, &dstRect);
}
