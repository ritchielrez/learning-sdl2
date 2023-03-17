#include "GameObject.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

GameObject::GameObject(SDL_Texture *texture, uint32_t xPos, uint32_t yPos, SDL_Renderer *renderer)
    : mTexture(texture), mSrcRect({0, 0, 0, 0}), mDstRect({0, 0, 0, 0}), mRenderer(renderer)
{
    mXPos = xPos * 4;
    mYPos = yPos * 4;
}

void GameObject::render()
{
    SDL_RenderCopy(mRenderer, mTexture, &mSrcRect, &mDstRect);
}

void GameObject::update(double deltaTime)
{
    mSrcRect.x = 0;
    mSrcRect.y = 0;
    mSrcRect.w = 32;
    mSrcRect.h = 32;

    mDstRect.x = mXPos;
    mDstRect.y = mYPos;
    mDstRect.w = mSrcRect.w * ENTITY_SCALE;
    mDstRect.h = mSrcRect.h * ENTITY_SCALE;
}
