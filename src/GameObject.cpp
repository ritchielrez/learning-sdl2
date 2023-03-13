#include "Game.hpp"
#include "GameObject.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

GameObject::GameObject(SDL_Texture* texture, uint32_t xPos, uint32_t yPos, SDL_Renderer *renderer) {
	mRenderer = renderer;
	objTexture = texture;
	mXPos = xPos;
	mYPos = yPos;
}

void GameObject::render() {
	SDL_RenderCopy(mRenderer, objTexture, &mSrcRect, &mDstRect);
}

void GameObject::update() {
	mSrcRect.x = 0;
	mSrcRect.y = 0;
	mSrcRect.w = 32;
	mSrcRect.h = 32;

	mDstRect.x = mXPos;
	mDstRect.y = mYPos;
	mDstRect.w = mSrcRect.w * ENTITY_SCALE;
	mDstRect.h = mSrcRect.h * ENTITY_SCALE;
}