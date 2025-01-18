#include <SDL.h>
// #include <stdlib.h>
#include <stdio.h>

#define bool char
#define true 0
#define false 1

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[]) {
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL_Init: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
      printf("SDL_CreateWindow: %s\n", SDL_GetError());
    } else {
      screenSurface = SDL_GetWindowSurface(window);
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
      SDL_UpdateWindowSurface(window);
      SDL_Event e; bool quit = false; while(quit == false) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) quit = true;
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}