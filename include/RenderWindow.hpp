#pragma once
#include "Entity.hpp"
#include "Player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture *loadTexture(const char *filePath);
  void clear();
  void render(Player &player, int scale, int frame);
  void render(Vector2f pos, SDL_Texture *texture, int scale);
  void render(Entity &entity, int scale);
  void render(Entity &entity);
  void display();
  int getRefreshRate();
  bool checkCollision(Player a, Entity b);
  ~RenderWindow();

  private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
