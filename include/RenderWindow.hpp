#pragma once
#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture *loadTexture(const char *filePath);
  void clear();
  void render(Entity &entity);
  void display();
  ~RenderWindow();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
