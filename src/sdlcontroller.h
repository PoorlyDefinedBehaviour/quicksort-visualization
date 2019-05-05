#define SDL_MAIN_HANDLED
#include "../include/SDL2/SDL.h"

static constexpr int WINDOW_WIDTH = 1600;
static constexpr int WINDOW_HEIGHT = 720;

class SDLController
{
public:
  SDLController() = delete;
  static void init();
  static void renderRectangle(const int &x, const int &y, const int &width, const int &height);
  static void updateScreen();
  static void clearScren();
  static void setRendererColor(const int &r, const int &g, const int &b, const int &a = 0);
  static void exit();

private:
  static SDL_Window *window;
  static SDL_Renderer *renderer;
};