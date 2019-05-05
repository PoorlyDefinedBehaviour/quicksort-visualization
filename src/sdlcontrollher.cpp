#include "sdlcontroller.h"

SDL_Window *SDLController::window = nullptr;
SDL_Renderer *SDLController::renderer = nullptr;

void SDLController::init()
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  window = SDL_CreateWindow("Quicksort visualization",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            WINDOW_WIDTH,
                            WINDOW_HEIGHT,
                            SDL_WINDOW_OPENGL);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(renderer, 0xff, 0xb4, 0xff, 0xff);
}

void SDLController::renderRectangle(const int &x, const int &y, const int &width, const int &height)
{
  SDL_Rect rectangle;
  rectangle.x = x;
  rectangle.y = y;
  rectangle.w = width;
  rectangle.h = height;

  SDL_RenderFillRect(renderer, &rectangle);
}

void SDLController::setRendererColor(const int &r, const int &g, const int &b, const int &a)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDLController::updateScreen()
{
  SDL_RenderPresent(renderer);
  SDL_RenderClear(renderer);
}

void SDLController::clearScren()
{
  SDL_RenderClear(renderer);
}

void SDLController::exit()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}