#include <iostream>
#include <thread>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "headers/globals.h"
#include "headers/utilitis/board.h"
#include "headers/utilitis/commands.h"
#include "headers/utilitis/hud.h"
#include "headers/utilitis/menu.h"
#include "headers/game.h"
#include "headers/player.h"
#include "headers/inputHandler.h"
#include "headers/iteams.h"

using namespace std;

//Player player;

int main()
{
    srand(time(NULL));
//    gameItems::loadWeapons();
//    Menu::menu();
//    thread inputThread(Input);
//    MainGame::drawBoard();
//    MainGame::drawHud();
    while (ProgramOpenState) {
        Sleep(500);
        cout << "dupa";
    }
//    inputThread.detach();
//    return 0;
}
