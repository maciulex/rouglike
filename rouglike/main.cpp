#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>

#include "headers/global.hpp"
#include "headers/game.hpp"
#include "headers/player.hpp"
#include "headers/input.hpp"
#include "headers/fight/monsters.hpp"
#include "headers/fight/fight.hpp"
#include "headers/utilitis/items.hpp"
#include "headers/utilitis/board.hpp"
#include "headers/utilitis/hud.hpp"
#include "headers/utilitis/menu.hpp"
#include "headers/utilitis/fight.hpp"
#include "headers/fight/attacks.hpp"

using namespace std;

Player player;

int main()
{
    srand(time(NULL));

    Monsters::loadMonsters();
    gameItems::loadIteams();
    Attacks::loadAttacks();

    player.variables.attacksWarrior[0] = 0;
    player.variables.attacksWarrior[1] = 1;

    Board::drawBlank();
    Menu::menu();

    thread inputThread(Input);
    Board::drawGame();

    Fight::engineFight();

    while (ProgramOpenState) {
        Sleep(500);
    }
    return 0;
}
