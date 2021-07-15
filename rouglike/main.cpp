#include <iostream>
#include <thread>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "headers/globals.h"
#include "headers/game.h"
#include "headers/player.h"
#include "headers/inputHandler.h"
#include "headers/iteams.h"

using namespace std;

Player player;

int main()
{
    srand(time(NULL));
    gameItems::loadWeapons();
    MainGame::menu::menu();
    thread inputThread(Input);
    MainGame::drawBoard();
    MainGame::drawHud();
    while (ProgramOpenState) {
        Sleep(500);
    }
    inputThread.detach();
    return 0;
}
