#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

class GameObject
{
  public:
    GameObject(const char *texture, uint32_t xPos, uint32_t yPos);
    void update(double deltaTime);
    void render();

  private:
    uint32_t mXPos, mYPos;
    SDL_Texture *mTexture;
    SDL_Rect mSrcRect;
    SDL_Rect mDstRect;
};
