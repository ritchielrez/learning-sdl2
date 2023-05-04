#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"
#include "Vector2D.hpp"

#include "Component.hpp"

#include <cstdint>

class RenderComponent : public Component
{
  public:
    Vector2D mPos;
    uint16_t mScale;
    SDL_Rect mSrcRect;
    SDL_FRect mDstRect;
    SDL_Texture *mTexture;

    RenderComponent(const char *texture, Vector2D pos, uint16_t scale)
        : mSrcRect({0, 0, 0, 0}), mDstRect({0, 0, 0, 0}), mPos(pos), mScale(scale)
    {
        mTexture = TextureManager::load(texture);
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

        mDstRect.x = mPos.x * mScale;
        mDstRect.y = mPos.y * mScale;
        mDstRect.w = mSrcRect.w * mScale;
        mDstRect.h = mSrcRect.h * mScale;
    }

    inline void render() override
    {
        TextureManager::render(mTexture, mSrcRect, mDstRect);
    }
};
