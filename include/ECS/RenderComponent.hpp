#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

#include "Component.hpp"

#include "PositionComponent.hpp"

#include <cstdint>

class RenderComponent : public Component
{
  public:
    PositionComponent *mPos;
    uint16_t mScale;
    SDL_Rect mSrcRect, mDstRect;
    SDL_Texture *mTexture;

    RenderComponent(const char *texture, uint16_t scale) : mSrcRect({0, 0, 0, 0}), mDstRect({0, 0, 0, 0}), mScale(scale)
    {
        mTexture = TextureManager::load(texture);
    }

    void init() override
    {
        mPos = &entity->getComponent<PositionComponent>();
        mPos->x *= mScale;
        mPos->y *= mScale;
    }

    void update(double dt) override
    {
        mSrcRect.x = 0;
        mSrcRect.y = 0;
        mSrcRect.w = 32;
        mSrcRect.h = 32;

        mDstRect.x = mPos->x;
        mDstRect.y = mPos->y;
        mDstRect.w = mSrcRect.w * mScale;
        mDstRect.h = mSrcRect.h * mScale;
    }

    inline void render() override
    {
        TextureManager::render(mTexture, mSrcRect, mDstRect);
    }
};
