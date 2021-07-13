#include "../headers/game.h"
#include "../headers/player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "../lib/color.hpp"

using namespace std;

extern Player player;

bool MainGame::getData::getDataInBattle() {
    return GameVariables.battle;
}

int MainGame::getData::getDataBoard(int y, int x) {
    return GameVariables.board[y][x];
}
void MainGame::getData::setSpecialMessages(string text, int row) {
    GameVariables.specialMesseges[row] = text;
}

void MainGame::menu::menu() {
    int choice;
    cout << "-----MENU-----" << endl;
    cout << "1) Nowa gra" << endl;
    cout << "2) Wczytaj gre" << endl;
    cout << "3) Opcje" << endl;
    cout << "4) Wyjdz" << endl;
    cin >> choice;
    if (cin.fail()) {
        menuFail();
    }
    switch (choice) {
        case 1:
            newGame();
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:
            exit(0);
        break;
        default:
            menuFail();
        break;
    }
};
void::MainGame::menu::menuFail() {
    cin.clear();
    cin.ignore(1000, '\n');
    system("cls");
    menu();
}
void MainGame::menu::newGame() {
    char boolChoice;
    int intChoice;
    cout << "Trudnosc: (1-5) 1 - latwy, 3 - normaly, 5 trudny" << endl;
    cin >> intChoice;
    if (cin.fail()) {
        menuFail();
    }
    switch (intChoice) {
        case 1:
            GameVariables.difficulty = 0.5;
        break;
        case 2:
            GameVariables.difficulty = 0.75;
        break;
        case 3:
            GameVariables.difficulty = 1;
        break;
        case 4:
            GameVariables.difficulty = 1.25;
        break;
        case 5:
            GameVariables.difficulty = 1.5;
        break;
        default:
            menuFail();
        break;
    }
    cout << "Randomowy seed? (T/N): " << endl;
    cin >> boolChoice;
    if (cin.fail()) {
        menuFail();
    }
    if (boolChoice == 't' || boolChoice == 'T') {
        GameVariables.seed = "falseNotNULLSeed";
    } else {
        cout << "Podaj seed gry: ";
        cin >> GameVariables.seed;
        if (cin.fail()) {
            menuFail();
        }
    }
    GameVariables.width = 100;
    GameVariables.height = 50;
    generateWord();
}
void MainGame::generateWord() {
    if (GameVariables.seed == "falseNotNULLSeed"){
        srand(time(NULL));
    } else {
        srand(hash<string>{}(GameVariables.seed));
    }
    int height = GameVariables.height, width = GameVariables.width;
    GameVariables.board = new int *[height];
    for (int y = 0; y < height; y++) {
        GameVariables.board[y] = new int [width];
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height-1) {
                GameVariables.board[y][x] = -1;
            } else if (x == 0 || x == width-1) {
                GameVariables.board[y][x] = -2;
            } else {
                int r;
                if (y > 15 && y < 35 && x > 30 && x < 70) {
                    r = rand()%5+1;
                } else {
                    r = rand()%3+1;
                }
                if (r!=1) {
                    GameVariables.board[y][x] = 0;
                } else {
                    GameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (GameVariables.board[y][x] == -1 || GameVariables.board[y][x] == -2) {
                continue;
            }
            for (int smooth = 0; smooth < 1; smooth++) {
                int wall = 0;
                for (int Sy = -1; Sy <= 1; Sy++) {
                    for (int Sx = -1; Sx <= 1; Sx++) {
                        if (GameVariables.board[y+Sy][x+Sx] != 0) {
                            wall += 1;
                        }
                    }
                }
                if (wall > 5) {
                    GameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = -3; y <= 3; y++) {
        for (int x = -3; x <= 3; x++) {
            if ((y == -3 || y == 3) && (x == -3 || x == 3)) {
                GameVariables.board[height/2+y][width/2+x] = 2;
            } else {
                GameVariables.board[height/2+y][width/2+x] = 0;
            }
        }
    }
    player.variables.x = width/2;
    player.variables.y = height/2;
}

void MainGame::drawBoard() {
    int height = GameVariables.height, width = GameVariables.width;
    if (GameVariables.fastDrawBoard) {

    } else {
        for (int y = 0; y < height; y++) {
            cout << "\t";
            for (int x = 0; x < width; x++) {
                if (y == player.variables.y && x == player.variables.x) {
                    cout << dye::aqua('P');
                    continue;
                }
                switch(GameVariables.board[y][x]) {
                    case -1:
                        cout << '-';
                    break;
                    case -2:
                        cout << '|';
                    break;
                    case 0:
                        cout << " ";
                    break;
                    case 1:
                        cout << char(219);
                    break;
                    case 2:
                        cout << dye::yellow(char(219));
                    break;
                }
            }
            switch (y) {
                case 25:
                    cout << "\t" << GameVariables.specialMesseges[0];
                    GameVariables.specialMesseges[0] = "";
                break;
                case 26:
                    cout << "\t" << GameVariables.specialMesseges[1];
                    GameVariables.specialMesseges[1] = "";
                break;
                case 27:
                    cout << "\t" << GameVariables.specialMesseges[2];
                    GameVariables.specialMesseges[2] = "";
                break;
                case 28:
                    cout << "\t" << GameVariables.specialMesseges[3];
                    GameVariables.specialMesseges[3] = "";
                break;
                case 29:
                    cout << "\t" << GameVariables.specialMesseges[4];
                    GameVariables.specialMesseges[4] = "";
                break;
            }
            cout<<endl;
        }
    }
};
void MainGame::drawHud() {
    char *endLine = "     | \n";
    char *l1s1 = "\t---------------------------------------------------------------------------------------------------- \n";
    char *l2s1 = "\t|                                                                                    hp: ";
    char *l3s1 = "\t|                                                                                        ";
    char *l4s1 = "\t|   |------------| |------------| |------------| |------------| |------------|       mp: ";
    char *l5s1;
    char *l6s1 = "\t|   |------------| |------------| |------------| |------------| |------------|       sp: ";
    char *l7s1 = "\t|                                                                                    st: ";
    char *l8s1 = "\t|                                                                                    it: ";
    switch(GameVariables.hud) {
        case 0:
            l5s1 = "\t|   | Walcz      | | Cwicz      | | Przedmioty | | Statystyki | |    Menu    |           ";
        break;
        case -2:
            l5s1 = "\t|   | Walke      | | Rozmowe    | | Magie      | | Odnow mp   | |   Powrot   |           ";
        break;
        case -1:
            l5s1 = "\t|   | Wojownik   | | Mag        | | Uciekaj    | | Itemy      | | Powrot     |           ";
        break;
    }
    cout << string(l1s1)+l2s1 << dye::red(player.variables.healthString[0])<<player.variables.healthString[1] << string(endLine)+l3s1
    << dye::red(player.variables.healthString[2]) << player.variables.healthString[3] << endLine
    << l4s1 << dye::blue(player.variables.manaString[0]) << player.variables.manaString[1] << endLine << l5s1 << player.variables.manaString[2] << player.variables.manaString[3]
    << endLine << l6s1 << player.variables.speedString << endLine << l7s1 << player.variables.strengeString << endLine << l8s1 << player.variables.itelligenceString << endLine << l1s1;
}
void MainGame::DrawBlank() {
    string blank = "";
    for (int i = 0; i < 40; i++) {
        blank += "\n";
    }
    cout << blank;
}
void MainGame::drawGame() {
    DrawBlank();
    if (GameVariables.battle) {

    } else {
        drawBoard();
    }
    drawHud();
}
int MainGame::useCommand(string command) {
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
        switch (hash<string>{}(commands[i])) {
            case 11809324432133475174:
//              ruch, move
//                cout << " ; " << commands[i] << " : " << commands[i+1] << " : " << commands[i+2] << " ; ";
//                system("pause");
                if (commands[i+1] == "" || commands[i+2] == "") break;
                int where = stoi(commands[i+2]);
                if (where < 1 && where > 100) break;
                switch (hash<string>{}(commands[i+1])) {
                    case 15668420055513320597:
//                        lewo, left
//                        cout << "lewo " << where;
//                        system("pause");
                        player.playerMove(where*-1,0,false);
                        drawGameIsRequired = false;
                    break;
                    case 11086085042462871678:
//                        prawo, right
//                        cout << "prawo " << where;
//                        system("pause");
                        player.playerMove(where,0,false);
                        drawGameIsRequired = false;
                    break;
                    case 8463621150016919774:
                    case 578713186308108379:
//                        góra, top
//                        cout << "góra " << where;
//                        system("pause");
                        player.playerMove(0,where*-1,false);
                        drawGameIsRequired = false;
                    break;
                    case 4702917268846209421:
                    case 1338332856947247205:
//                        dó³, bottom
//                        cout << "dó³ " << where;
//                        system("pause");
                        player.playerMove(0,where,false);
                        drawGameIsRequired = false;
                    break;
                }
                drawGame();
            break;
        }
    }
    if (drawGameIsRequired) {
        return 1;
    }
    return 0;
}


