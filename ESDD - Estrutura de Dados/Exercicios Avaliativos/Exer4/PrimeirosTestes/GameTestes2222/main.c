#include ".\src\include\SDL2\SDL.h"
#include ".\src\include\SDL2\SDL_image.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int x, y;
  short life;
  char* name;
} Player;

typedef struct {
  Player player;
  SDL_Texture* dino;
} GameState;



int processEvents(SDL_Window* window, GameState* gameState);
void doRender(SDL_Renderer* renderer, GameState* gameState);

int main(int argc, char* argv[])
{
  bool stop = false;

  SDL_Window* window = NULL;
  SDL_Renderer* render = NULL;
  SDL_Surface* dinoSurface = NULL;

  GameState gameState;

  gameState.player.x = 220;
  gameState.player.y = 140;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Jogo mais foda do mes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // dinoSurface = IMG_Load("./images/t_rex.png");
  // if (dinoSurface == NULL) {
  //   printf("Imagem nao encontrada!");
  //   SDL_Quit();
  //   return 1;
  // }

  gameState.dino = SDL_CreateTextureFromSurface( render, dinoSurface);
  SDL_FreeSurface(dinoSurface);

  while (!stop) {
    stop = processEvents(window, &gameState);

    doRender(render, &gameState);
  }

  SDL_DestroyTexture(gameState.dino);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(render);

  SDL_Quit();
  return 0;
}


int processEvents(SDL_Window* window, GameState* gameState)
{
  SDL_Event event;
  bool stop;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_WINDOWEVENT_CLOSE:
        if (window) {
          SDL_DestroyWindow(window);
          window = NULL;
          stop = true;
        }
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            stop = true;
            break;
        }
        break;
      case SDL_QUIT:
        stop = true;
        break;
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT])
      gameState->player.x -= 10;
    if (state[SDL_SCANCODE_RIGHT])
      gameState->player.x += 10;
    if (state[SDL_SCANCODE_UP])
      gameState->player.y -= 10;
    if (state[SDL_SCANCODE_DOWN])
      gameState->player.y += 10;
  }
  return stop;
}

void doRender(SDL_Renderer* renderer, GameState* gameState)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_Rect rect = { gameState->player.x, gameState->player.y, 0, 0 };
  SDL_RenderFillRect(renderer, &rect);

  SDL_Rect dinoRect = {gameState->player.x, gameState->player.y, 64, 64};
  SDL_RenderCopy(renderer, gameState->dino, NULL, &dinoRect);

  SDL_RenderPresent(renderer);
}