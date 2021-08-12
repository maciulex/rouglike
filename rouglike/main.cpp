#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>

#include "headers/global.hpp"
#include "headers/game.hpp"
#include "headers/player.hpp"
#include "headers/input.hpp"
#include "headers/utilitis/board.hpp"
#include "headers/utilitis/hud.hpp"
#include "headers/utilitis/menu.hpp"


using namespace std;

Player player;

int main()
{
    srand(time(NULL));
    Menu::menu();
    thread inputThread(Input);
    Board::drawBoard();
    Hud::drawHud();
    while (ProgramOpenState) {
        Sleep(500);
    }
    return 0;
}
