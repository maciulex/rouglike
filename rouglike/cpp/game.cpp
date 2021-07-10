#include "../headers/game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../lib/color.hpp"

using namespace std;

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
}

void MainGame::drawBoard() {
    int height = gameVariables.height, width = gameVariables.width;
    if (gameVariables.fastDrawBoard) {

    } else {
        for (int y = 0; y < height; y++) {
            cout << "\t";
            for (int x = 0; x < width; x++) {
                //if (i == player.y && j == player.x) {
                //    cout << dye::aqua('P');
                //    continue;
                //}
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
                    gameVariables.specialMesseges[0]="";
                break;
                case 26:
                    cout << "\t" << gameVariables.specialMesseges[1];
                    gameVariables.specialMesseges[1]="";
                break;
                case 27:
                    cout << "\t" << gameVariables.specialMesseges[2];
                    gameVariables.specialMesseges[2]="";
                break;
                case 28:
                    cout << "\t" << gameVariables.specialMesseges[3];
                    gameVariables.specialMesseges[3]="";
                break;
                case 29:
                    cout << "\t" << gameVariables.specialMesseges[4];
                    gameVariables.specialMesseges[4]="";
                break;
            }
            cout<<endl;
        }
    }
};

