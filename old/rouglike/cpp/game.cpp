#include "../headers/game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

//#include "../headers/globals.h"

using namespace std;


void MainGame::generateWord() {
////    cout << GameVariables.width;
//    if (GameVariables.seed == "falseNotNULLSeed"){
//        srand(time(NULL));
//    } else {
//        srand(hash<string>{}(GameVariables.seed));
//    }
//    int height = GameVariables.height, width = GameVariables.width;
//    GameVariables.board = new int *[height];
//    for (int y = 0; y < height; y++) {
//        GameVariables.board[y] = new int [width];
//        for (int x = 0; x < width; x++) {
//            if (y == 0 || y == height-1) {
//                GameVariables.board[y][x] = -1;
//            } else if (x == 0 || x == width-1) {
//                GameVariables.board[y][x] = -2;
//            } else {
//                int r;
//                if (y > 15 && y < 35 && x > 30 && x < 70) {
//                    r = rand()%5+1;
//                } else {
//                    r = rand()%3+1;
//                }
//                if (r!=1) {
//                    GameVariables.board[y][x] = 0;
//                } else {
//                    GameVariables.board[y][x] = 1;
//                }
//            }
//        }
//    }
//    for (int y = 0; y < height; y++) {
//        for (int x = 0; x < width; x++) {
//            if (GameVariables.board[y][x] == -1 || GameVariables.board[y][x] == -2) {
//                continue;
//            }
//            for (int smooth = 0; smooth < 1; smooth++) {
//                int wall = 0;
//                for (int Sy = -1; Sy <= 1; Sy++) {
//                    for (int Sx = -1; Sx <= 1; Sx++) {
//                        if (GameVariables.board[y+Sy][x+Sx] != 0) {
//                            wall += 1;
//                        }
//                    }
//                }
//                if (wall > 5) {
//                    GameVariables.board[y][x] = 1;
//                }
//            }
//        }
//    }
//    for (int y = -3; y <= 3; y++) {
//        for (int x = -3; x <= 3; x++) {
//            if ((y == -3 || y == 3) && (x == -3 || x == 3)) {
//                GameVariables.board[height/2+y][width/2+x] = 2;
//            } else {
//                GameVariables.board[height/2+y][width/2+x] = 0;
//            }
//        }
//    }
//    GameVariables.level += 1;
//    player.variables.x = width/2;
//    player.variables.y = height/2;
}




int MainGame::useCommand(string command) {
//    bool drawGameIsRequired = true;
//    int commandsIndex = 0;
//    string commands[7] = {""};
//    for (int i = 0; i < command.length(); i++) {
//        if (commandsIndex == 6) break;
//        if (command[i] == ' ') {
//            //if (commandsIndex > 0 && commands[i-1] == "") {commandsIndex-=1; continue;}
//            commandsIndex += 1;
//            continue;
//        }
//        commands[commandsIndex] += command[i];
//    }
//    for (int i = 0; i <= commandsIndex; i++) {
//        int where;
//        switch (GameVariables.hud) {
//            case 1:
//               switch (hash<string>{}(commands[i])) {
//                    case 5772833367524736768:
////                      powrot
//                        GameVariables.hud = 0;
//                        drawGame();
//                        return 0;
//                    break;
//                    case 10743544026436958666:
////                      Zamien
//
//                    break;
//                    case 3260554669361923085:
////                      Wyrzuc
//
//                    break;
//                    case 3829121089218035508:
////                      Uzyj
//
//                    break;
//                    case 5366797971342239317:
////                      Szczegoly
//
//                    break;
//                }
//            break;
//            default:
//                switch (hash<string>{}(commands[i])) {
//                    case 11809324432133475174:
//                        if (GameVariables.hud != 0) return 1;
////                      ruch, move
////                      cout << " ; " << commands[i] << " : " << commands[i+1] << " : " << commands[i+2] << " ; ";
////                      system("pause");
//                        if (commands[i+1] == "" || commands[i+2] == "") break;
//                        where = stoi(commands[i+2]);
//                        if (where < 1 && where > 100) break;
//                        switch (hash<string>{}(commands[i+1])) {
//                            case 15668420055513320597:
////                                lewo, left
////                                cout << "lewo " << where;
////                                system("pause");
//                                player.playerMove(where*-1,0,false);
//                                drawGameIsRequired = false;
//                            break;
//                            case 11086085042462871678:
////                                prawo, right
////                                cout << "prawo " << where;
////                                system("pause");
//                                player.playerMove(where,0,false);
//                                drawGameIsRequired = false;
//                            break;
//                            case 8463621150016919774:
//                            case 578713186308108379:
////                                góra, top
////                                cout << "góra " << where;
////                                system("pause");
//                                player.playerMove(0,where*-1,false);
//                                drawGameIsRequired = false;
//                            break;
//                            case 4702917268846209421:
//                            case 1338332856947247205:
////                                dó³, bottom
////                                cout << "dó³ " << where;
////                                system("pause");
//                                player.playerMove(0,where,false);
//                                drawGameIsRequired = false;
//                            break;
//                        }
//                        drawGame();
//                    break;
//                    case 16249881897017512211:
//                        GameVariables.hud = 1;
//                        drawGame();
//                    break;
//                }
//            break;
//        }
//    }
//    if (drawGameIsRequired) {
//        return 1;
//    }
    return 0;
}


