#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

class GameObject
{
  private:
    uint32_t mXPos, mYPos;
    SDL_Texture *mTexture;
    SDL_Rect mSrcRect;
    SDL_Rect mDstRect;
    SDL_Renderer *mRenderer;

  public:
    GameObject(SDL_Texture *texture, uint32_t xPos, uint32_t yPos, SDL_Renderer *renderer);
    void update();
    void render();
};
