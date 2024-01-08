#include <iostream>

#include "SDL.h"
#undef main

using namespace std;

int main(int argc, char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* board = nullptr; 
    SDL_Surface* piece = nullptr;



    SDL_Texture* texture = nullptr;
    SDL_Event event;

    SDL_Rect positionRect;
    SDL_Rect dimensionRect;

    positionRect.x = 0;
    positionRect.y = 0;
    positionRect.w = 800;
    positionRect.h = 600;

    dimensionRect.x = 0;
    dimensionRect.y = 0;
    dimensionRect.w = 800;
    dimensionRect.h = 600;


    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    board = SDL_LoadBMP("assets/Board.bmp");
    piece = SDL_LoadBMP("assets/WhitePond.bmp");
    if (!board) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return 1;
    }

    texture = SDL_CreateTextureFromSurface(renderer, board);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return 1;
    }

    SDL_FreeSurface(board);
    board = nullptr;

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        //SDL_SetRenderDrawColor(renderer, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, &positionRect, &dimensionRect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}