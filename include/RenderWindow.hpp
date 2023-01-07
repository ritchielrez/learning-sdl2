#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  ~RenderWindow();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
