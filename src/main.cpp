#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "sdlcontroller.h"

template <typename T>
void drawArray(const T &array)
{
  const int RECTANGLE_WIDTH = WINDOW_WIDTH / (array.size() - 1);

  SDLController::setRendererColor(0, 0, 0);
  SDLController::renderRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

  SDLController::setRendererColor(100, 100, 100);

  for (int i = 0; i < array.size(); ++i)
  {
    SDLController::renderRectangle(i * RECTANGLE_WIDTH,
                                   WINDOW_HEIGHT - array[i],
                                   RECTANGLE_WIDTH,
                                   array[i]);
  }

  SDLController::updateScreen();
}

template <typename T>
void quicksort(T &array, const int &start, const int &end)
{
  if (start >= end)
    return;

  int pivotIndex = start;
  auto const &pivotValue = array[end];

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  frameStart = SDL_GetTicks();

  for (int i = start; i < end; ++i)
  {
    if (array[i] < pivotValue)
    {
      std::swap(array[i], array[pivotIndex]);
      ++pivotIndex;
    }
  }

  frameTime = SDL_GetTicks() - frameStart;

  if (frameDelay > frameTime)
  {
    SDL_Delay(frameDelay - frameTime);
  }

  drawArray(array);

  std::swap(array[pivotIndex], array[end]);

  quicksort(array, start, pivotIndex - 1);
  quicksort(array, pivotIndex + 1, end);
}

int main()
{
  srand(time(nullptr));

  SDLController::init();

  std::vector<int> array(200);
  std::generate(array.begin(), array.end(), []() { return rand() % WINDOW_HEIGHT; });

  quicksort(array, 0, array.size() - 1);
}