#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

#include "Component.hpp"
#include <cstdint>

class RenderComponent : public Component
{
  public:
    uint32_t mXPos, mYPos;
    uint16_t mScale;
    SDL_Rect mSrcRect, mDstRect;
    SDL_Texture *mTexture;

    RenderComponent(const char *texture, uint32_t xPos, uint32_t yPos, uint16_t scale)
        : mSrcRect({0, 0, 0, 0}), mDstRect({0, 0, 0, 0}), mScale(scale)
    {
        mTexture = TextureManager::load(texture);

        mXPos = xPos * mScale;
        mYPos = yPos * mScale;
    }

    void init() override
    {
    }

    void update(double dt) override
    {
        mSrcRect.x = 0;
        mSrcRect.y = 0;
        mSrcRect.w = 32;
        mSrcRect.h = 32;

        mDstRect.x = mXPos;
        mDstRect.y = mYPos;
        mDstRect.w = mSrcRect.w * mScale;
        mDstRect.h = mSrcRect.h * mScale;
    }

    inline void render() override
    {
        TextureManager::render(mTexture, mSrcRect, mDstRect);
    }
};