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
   
    Board chessBoard(true);
    Screen screen;
    if (!screen.init()) {
        return 0;
    }
    while (true) {
        if (!screen.processSDLEvents()) {
            break;
        }
        screen.renderBoard(chessBoard.piece_positions);

    }
    screen.close();

    return 0;
}