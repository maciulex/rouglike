#include <iostream>
#include <thread>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "headers/globals.h"
#include "headers/inputHandler.h"
#include "headers/game.h"
using namespace std;


int main()
{
    srand(time(NULL));
    thread inputThread(Input);
    MainGame::menu::menu();
    MainGame::drawBoard();
    while (ProgramOpenState) {
        Sleep(500);
    }
    inputThread.detach();
    return 0;
}
