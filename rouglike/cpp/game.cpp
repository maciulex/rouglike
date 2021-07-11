#include "../headers/game.h"
#include "../headers/player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../lib/color.hpp"

using namespace std;

extern Player player;
MainGame::GameVariables gameVariables;

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
            gameVariables.difficulty = 0.5;
        break;
        case 2:
            gameVariables.difficulty = 0.75;
        break;
        case 3:
            gameVariables.difficulty = 1;
        break;
        case 4:
            gameVariables.difficulty = 1.25;
        break;
        case 5:
            gameVariables.difficulty = 1.5;
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
        gameVariables.seed = "falseNotNULLSeed";
    } else {
        cout << "Podaj seed gry: ";
        cin >> gameVariables.seed;
        if (cin.fail()) {
            menuFail();
        }
    }
    gameVariables.width = 100;
    gameVariables.height = 50;
    generateWord();
}
void MainGame::generateWord() {
    if (gameVariables.seed == "falseNotNULLSeed"){
        srand(time(NULL));
    } else {
        srand(hash<string>{}(gameVariables.seed));
    }
    int height = gameVariables.height, width = gameVariables.width;
    gameVariables.board = new int *[height];
    for (int y = 0; y < height; y++) {
        gameVariables.board[y] = new int [width];
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height-1) {
                gameVariables.board[y][x] = -1;
            } else if (x == 0 || x == width-1) {
                gameVariables.board[y][x] = -2;
            } else {
                int r;
                if (y > 15 && y < 35 && x > 30 && x < 70) {
                    r = rand()%5+1;
                } else {
                    r = rand()%3+1;
                }
                if (r!=1) {
                    gameVariables.board[y][x] = 0;
                } else {
                    gameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (gameVariables.board[y][x] == -1 || gameVariables.board[y][x] == -2) {
                continue;
            }
            for (int smooth = 0; smooth < 1; smooth++) {
                int wall = 0;
                for (int Sy = -1; Sy <= 1; Sy++) {
                    for (int Sx = -1; Sx <= 1; Sx++) {
                        if (gameVariables.board[y+Sy][x+Sx] != 0) {
                            wall += 1;
                        }
                    }
                }
                if (wall > 5) {
                    gameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = -3; y <= 3; y++) {
        for (int x = -3; x <= 3; x++) {
            if ((y == -3 || y == 3) && (x == -3 || x == 3)) {
                gameVariables.board[height/2+y][width/2+x] = 2;
            } else {
                gameVariables.board[height/2+y][width/2+x] = 0;
            }
        }
    }
    player.variables.x = width/2;
    player.variables.y = height/2;
}

void MainGame::drawBoard() {
    int height = gameVariables.height, width = gameVariables.width;
    if (gameVariables.fastDrawBoard) {

    } else {
        for (int y = 0; y < height; y++) {
            cout << "\t";
            for (int x = 0; x < width; x++) {
                if (y == player.variables.y && x == player.variables.x) {
                    cout << dye::aqua('P');
                    continue;
                }
                switch(gameVariables.board[y][x]) {
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
                    cout << "\t" << gameVariables.specialMesseges[0];
                    gameVariables.specialMesseges[0] = "";
                break;
                case 26:
                    cout << "\t" << gameVariables.specialMesseges[1];
                    gameVariables.specialMesseges[1] = "";
                break;
                case 27:
                    cout << "\t" << gameVariables.specialMesseges[2];
                    gameVariables.specialMesseges[2] = "";
                break;
                case 28:
                    cout << "\t" << gameVariables.specialMesseges[3];
                    gameVariables.specialMesseges[3] = "";
                break;
                case 29:
                    cout << "\t" << gameVariables.specialMesseges[4];
                    gameVariables.specialMesseges[4] = "";
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
    switch(gameVariables.hud) {
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

