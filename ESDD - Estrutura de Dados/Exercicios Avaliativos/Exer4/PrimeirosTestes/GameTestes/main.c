#include "SDL2-devel-2.28.4-mingw/SDL2-2.28.4/x86_64-w64-mingw32/include/SDL2/SDL.h"

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *render;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Teste de telinha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    

    return 0;
}

