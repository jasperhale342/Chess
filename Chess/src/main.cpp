#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <board.h>
#include "SDL.h"
#include "Screen.h"
#undef main

using namespace std;
using namespace chess;

typedef struct coor {
    int x;
    int y;
}coor;

bool canGrab(int mouseX, int mouseY, vector <vector<int>> positions)
{
    
    cout << mouseX << ", " << mouseY << endl;
    for (auto position : positions) {
        cout << "position: " << position[0] << ", " << position[1] << endl;
        if (abs(mouseX - position[0]) < 50 && abs(mouseY - position[1]) < 50) {
            return true;
        }
    }

    return false;
}

int calculateSlot(int x) {
    if (x >= 100) {
        x = x - x % 100;
    }
    else {
        x = 0;
    }
    
    return x;

}

int main(int argc, char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* board = nullptr; 
    SDL_Surface* piece = nullptr;



    SDL_Texture* pieceTexture = nullptr;
    SDL_Texture* boardTexture = nullptr;
    SDL_Event event;

    SDL_Rect positionRect;
    SDL_Rect dimensionRect;

    SDL_Rect piecePositionReact;
    SDL_Rect pieceDimensionRect;

    positionRect.x = 0;
    positionRect.y = 0;
    positionRect.w = 800;
    positionRect.h = 800;

    dimensionRect.x = 0;
    dimensionRect.y = 0;
    dimensionRect.w = 800;
    dimensionRect.h = 800;

    piecePositionReact.x = 5;
    piecePositionReact.y = 5;
    piecePositionReact.w = 100;
    piecePositionReact.h = 100;

    pieceDimensionRect.x = 0;
    pieceDimensionRect.y = 0;
    pieceDimensionRect.w = 100;
    pieceDimensionRect.h = 100;

    //screen.init()
    //board
    Board chessBoard(true);
    Screen screen;
    if (!screen.init()) {
        return 0;
    }



    if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    board = SDL_LoadBMP("assets/Board.bmp");
    piece = SDL_LoadBMP("assets/WhitePond.bmp");
    if (!board || !piece) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return 1;
    }

    boardTexture = SDL_CreateTextureFromSurface(renderer, board);
    pieceTexture = SDL_CreateTextureFromSurface(renderer, piece);
    if (!boardTexture || !pieceTexture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return 1;
    }
   


    SDL_FreeSurface(board);
    SDL_FreeSurface(piece);
    board = nullptr;
    Sint32 mouseX;
    Sint32 mouseY;
    bool isGrabbing = false;
    int height = 800;
    int width = 800;

    vector <vector<int>> positions{ {pieceDimensionRect.x, pieceDimensionRect.y} };

    
    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }

        if (event.type == SDL_MOUSEBUTTONUP && isGrabbing) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                isGrabbing = false;
                cout << "placing at: " << event.motion.x << ", " << event.motion.y << endl;
                positions.at(0)[0] = calculateSlot(event.motion.x);
                positions.at(0)[1] = calculateSlot(event.motion.y);
                pieceDimensionRect.x = calculateSlot(event.motion.x);
                pieceDimensionRect.y = calculateSlot(event.motion.y);
            }
        }
        if (event.type == SDL_MOUSEMOTION && isGrabbing) {
            pieceDimensionRect.x = event.motion.x;
            pieceDimensionRect.y = event.motion.y;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            cout << "left is being pressed" << endl;
            if (event.button.button == SDL_BUTTON_LEFT) {
             
                 if (canGrab((int)event.motion.x, (int)event.motion.y, positions)) {
                    cout << "grabbing on" << endl;   
                    isGrabbing = true;
                }
                
            }
           
        }
        //SDL_SetRenderDrawColor(renderer, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, texture, &positionRect, &dimensionRect);
        SDL_SetRenderTarget(renderer, boardTexture);
        SDL_RenderCopy(renderer, boardTexture, &positionRect, &dimensionRect);
   /*     SDL_SetRenderTarget(renderer, boardTexture);*/
        SDL_RenderCopy(renderer, pieceTexture, &piecePositionReact, &pieceDimensionRect);
        //SDL_RenderCopy(renderer, pTripodTexture, &l_sourceRect, &l_sourceRect);
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(pieceTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}