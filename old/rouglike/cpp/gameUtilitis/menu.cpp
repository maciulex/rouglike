#include "../../headers/utilitis/menu.h"
#include <iostream>
#include "../../headers/globals.h"
#include "../../headers/game.h"
using namespace std;

void Menu::menu() {
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
void Menu::menuFail() {
    cin.clear();
    cin.ignore(1000, '\n');
    system("cls");
    menu();
}
void Menu::newGame() {
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
    MainGame::generateWord();
}
