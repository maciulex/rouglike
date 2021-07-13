#include "../headers/inputHandler.h"
#include "../headers/game.h"
#include "../headers/player.h"

#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

extern Player player;
extern bool ProgramOpenState;
extern int InputOutputDirection;

void Input() {
    std::string command = "";
    while (ProgramOpenState) {
        char input;
        bool commandB = true;
        input = getch();
//        if (fightDir != -1) {
//            switch ((int)input) {
//                case 77:
//                    fightInput = 1;
//                    cout << (char)16 << endl;
//                break;
//                case 75:
//                    fightInput = 2;
//                    cout << (char)17 << endl;
//                break;
//                case 72:
//                    fightInput = 3;
//                    cout << (char)30 << endl;
//                break;
//                case 80:
//                    fightInput = 4;
//                    cout << (char)31 << endl;
//                break;
//            }
//            continue;
//        }
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
                    if (MainGame::useCommand(command) == 1)
                        MainGame::drawGame();
                    }
                    command = "";
                    commandB = false;
            break;
            case 8:
                if (command.length() > 0) {
                    command.erase(command.length()-1);
                    MainGame::drawGame();
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
