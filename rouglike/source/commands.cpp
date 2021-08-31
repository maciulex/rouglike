#include "../headers/commands.hpp"

#include "../headers/global.hpp"
#include "../headers/utilitis/board.hpp"
#include "../headers/player.hpp"
#include "../headers/utilitis/menu.hpp"
#include "../headers/debug/debug.hpp"

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
                        goBack:
                        if (GameVariables.battle) GameVariables.hud = 3;
                        else GameVariables.hud = 0;
                        Board::drawGame();
                        return 0;
                    break;
                    case 3260554669361923085:
//                      Wyrzuc
                        player.dropIteam(commands[i+1]);
                    break;
                    case 3829121089218035508:
//                      Uzyj
                        try {
                            if (!player.tryUseIteam(stoi(commands[i+1]))) cout << endl << "Nie mozna uzyc tego itema!" << endl;
                        } catch (exception &e) {
                            cout << "error nie poprawne dane";
                        }
                    break;
                    case 5366797971342239317:
//                      Szczegoly
                        try {
                            where = stoi(commands[i+1]);
                            if (where < 1 || where > player.variables.inventorySize) {
                                cout << "Out of range";
                                system("pause");
                                continue;
                            }
                            where -= 1;
                            player.drawMoreDataAbout(where);
                            system("pause");
                        } catch (exception &e) {
                            cout << "error nie poprawne dane";
                        }
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
                goto defaultSwitch;
            break;
            case 2:
                goto defaultSwitch;
            break;
            case 3:
                switch (hash<string>{}(commands[i])) {
                    case 16798379603612784844:
                        //wojownik
                        GameVariables.hud = 4;

                    break;
                    case 17053659922084647272:
                        //mag
                        GameVariables.hud = 5;
                    break;
                    case 16341394509686110479:
                        //uciekaj

                    break;
                }
            break;
            case 4:
                switch (hash<string>{}(commands[i])) {
                    case 16770126819965438330:
//                      atak
                    break;
                    case 5772833367524736768:
//                      powrot
                        goto goBack;
                    break;
                }
            break;
            case 5:
                switch (hash<string>{}(commands[i])) {
                    case 16770126819965438330:
//                      atak

                    break;
                    case 5772833367524736768:
//                      powrot
                        goto goBack;
                    break;
                }
            break;
            default:
                defaultSwitch:
                switch (hash<string>{}(commands[i])) {
                    case 11809324432133475174:
//                      ruch, move
                        if (GameVariables.hud != 0) return 1;
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
                    case 3427354763634449829:
                        //menu
                        Menu::menuInGame();
                    break;
                    case 6281556121102617670:
                        Debug::debug();
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
