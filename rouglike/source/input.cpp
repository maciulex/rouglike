#include "../headers/input.hpp"
#include "../headers/game.hpp"
#include "../headers/player.hpp"
#include "../headers/global.hpp"
#include "../headers/fight/fight.hpp"
#include "../headers/utilitis/board.hpp"
#include "../headers/commands.hpp"

#include <string>
#include <conio.h>
#include <iostream>

extern Player player;

bool dataGoToFight = false;
extern Fight::FightDataStruct FightData;

void Input() {
    std::string command = "";
    while (ProgramOpenState) {
        char input;
        bool commandB = true;
        input = getch();
        if (BlockInputThread) continue;

        switch ((int)input) {
            case 77:
                //cout << "prawo" << endl;
                player.playerMove(1,0);
                command = "";
                commandB = false;
            break;
            case 80:
                //cout << "dol" << endl;
                player.playerMove(0,1);
                command = "";
                commandB = false;
            break;
            case 75:
                //cout << "lewo" << endl;
                player.playerMove(-1,0);
                command = "";
                commandB = false;
            break;
            case 72:
                //cout << "gora" << endl;
                player.playerMove(0,-1);
                command = "";
                commandB = false;
            break;
            case 13:
                //enter
                if (command.length() > 0) {
                    if (useCommand(command) == 1)
                        Board::drawGame();
                    }
                    command = "";
                    commandB = false;
            break;
            case 8:
                if (command.length() > 0) {
                    command.erase(command.length()-1);
                    Board::drawGame();
                    std::cout << command;
                }
                commandB = false;
            break;
        }
        if (commandB) {
            command += input;
            std::cout << input;
        }
    }
}
void InputFight() {
    while (GameVariables.battle && !FightData.fastEndEnter) {
        char input;
        input = getch();
        switch ((int)input) {
            case 13:
                FightData.fastEndEnter = true;
                //FightData.acutalInputCombination-=1;
                //system("pause");
            break;
            case 77:
                Fight::addFightDirectory(1);
                std::cout << (char)16;
            break;
            case 75:
                Fight::addFightDirectory(2);
                std::cout << (char)17;
            break;
            case 72:
                Fight::addFightDirectory(3);
                std::cout << (char)30;
            break;
            case 80:
                Fight::addFightDirectory(4);
                std::cout << (char)31;
            break;
        }
        //FightData.acutalInputCombination+=1;
    }
}
