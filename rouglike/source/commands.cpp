#include "../headers/commands.hpp"

#include "../headers/global.hpp"
#include "../headers/utilitis/board.hpp"
#include "../headers/player.hpp"

#include <math.h>
#include <iostream>

using namespace std;

extern Player player;

int useCommand(string command) {
    bool drawGameIsRequired = true;
    int commandsIndex = 0;
    string commands[7] = {""};
    for (int i = 0; i < command.length(); i++) {
        if (commandsIndex == 6) break;
        if (command[i] == ' ') {
            //if (commandsIndex > 0 && commands[i-1] == "") {commandsIndex-=1; continue;}
            commandsIndex += 1;
            continue;
        }
        commands[commandsIndex] += command[i];
    }
    for (int i = 0; i <= commandsIndex; i++) {
        int where;
        switch (GameVariables.hud) {
            case 1:
               switch (hash<string>{}(commands[i])) {
                    case 5772833367524736768:
//                      powrot
                        GameVariables.hud = 0;
                        Board::drawGame();
                        return 0;
                    break;
                    case 3260554669361923085:
//                      Wyrzuc
                        player.dropIteam(commands[i+1]);
                    break;
                    case 3829121089218035508:
//                      Uzyj

                    break;
                    case 5366797971342239317:
//                      Szczegoly
                        where = stoi(commands[i+1]);
                        if (where < 1 || where > player.variables.inventorySize) {
                            cout << "Out of range";
                            system("pause");
                            continue;
                        }
                        where -= 1;
                        player.drawMoreDataAbout(where);
                        system("pause");
                    break;
                    case 14526079891305879776:
//                      >
                        if (player.variables.actualPage == ceil(player.variables.inventorySize/player.variables.inventoryOnePageItemAmount)) return 0;
                        player.variables.actualPage += 1;
                        Board::drawGame();
                    break;
                    case 1396094175042499165:
//                      <
                        if (player.variables.actualPage == 1) return 0;
                        player.variables.actualPage -= 1;
                        Board::drawGame();
                    break;
                }
            break;
            case 2:

            break;
            default:
                switch (hash<string>{}(commands[i])) {
                    case 11809324432133475174:
                        if (GameVariables.hud != 0) return 1;
//                      ruch, move
//                      cout << " ; " << commands[i] << " : " << commands[i+1] << " : " << commands[i+2] << " ; ";
//                      system("pause");
                        if (commands[i+1] == "" || commands[i+2] == "") break;
                        where = stoi(commands[i+2]);
                        if (where < 1 && where > 100) break;
                        switch (hash<string>{}(commands[i+1])) {
                            case 15668420055513320597:
//                                lewo, left
//                                cout << "lewo " << where;
//                                system("pause");
                                player.playerMove(where*-1,0,false);
                                drawGameIsRequired = false;
                            break;
                            case 11086085042462871678:
//                                prawo, right
//                                cout << "prawo " << where;
//                                system("pause");
                                player.playerMove(where,0,false);
                                drawGameIsRequired = false;
                            break;
                            case 8463621150016919774:
                            case 578713186308108379:
//                                góra, top
//                                cout << "góra " << where;
//                                system("pause");
                                player.playerMove(0,where*-1,false);
                                drawGameIsRequired = false;
                            break;
                            case 4702917268846209421:
                            case 1338332856947247205:
//                                dó³, bottom
//                                cout << "dó³ " << where;
//                                system("pause");
                                player.playerMove(0,where,false);
                                drawGameIsRequired = false;
                            break;
                        }
                        Board::drawGame();
                    break;
                    case 16249881897017512211:
                        //przedmioty
                        GameVariables.hud = 1;
                        Board::drawGame();
                    break;
                }
            break;
        }
    }
    if (drawGameIsRequired) {
        return 1;
    }
    return 0;
}
