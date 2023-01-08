#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture *loadTexture(const char *filePath);
  void clear();
  void render(SDL_Texture *texture);
  void display();
  ~RenderWindow();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
