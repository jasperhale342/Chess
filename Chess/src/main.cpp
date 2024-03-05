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

int main(int argc, char* args[])
{
   
    Board chessBoard(true);
    Screen screen;
    if (!screen.init()) {
        return 0;
    }
    while (true) {
        if (!screen.processSDLEvents()) {
            break;
        }
        screen.renderBoard();

    }
    screen.close();

    return 0;
}