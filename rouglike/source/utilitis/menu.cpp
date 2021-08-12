#include "../../headers/utilitis/menu.hpp"
#include "../../headers/global.hpp"
#include "../../headers/game.hpp"
#include "../../headers/debug/debug.hpp"
#include <iostream>

void Menu::menu() {
    int choice;
    std::cout << "-----MENU-----" << std::endl;
    std::cout << "1) Nowa gra" << std::endl;
    std::cout << "2) Wczytaj gre" << std::endl;
    std::cout << "3) Opcje" << std::endl;
    std::cout << "4) Wyjdz" << std::endl;
    std::cin >> choice;
    if (std::cin.fail()) {
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
        case 5:
            Debug::debug();
            menuFail();
        break;
        default:
            menuFail();
        break;
    }
};
void Menu::menuFail() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    system("cls");
    menu();
}
void Menu::newGame() {
    char boolChoice;
    int intChoice;
    std::cout << "Trudnosc: (1-5) 1 - latwy, 3 - normaly, 5 trudny" << std::endl;
    std::cin >> intChoice;
    if (std::cin.fail()) {
        menuFail();
    }
        switch (intChoice) {
            case 1:
                GameVariables.difficulty = 1;
            break;
            case 2:
                GameVariables.difficulty = 2;
            break;
            case 3:
                GameVariables.difficulty = 3;
            break;
            case 4:
                GameVariables.difficulty = 4;
            break;
            case 5:
                GameVariables.difficulty = 5;
            break;
            default:
                menuFail();
            break;
        }
        std::cout << "Randomowy seed? (T/N): " << std::endl;
        std::cin >> boolChoice;
        if (std::cin.fail()) {
            menuFail();
        }
        if (boolChoice == 't' || boolChoice == 'T') {
            GameVariables.seed = "falseNotNULLSeed";
        } else {
            std::cout << "Podaj seed gry: ";
            std::cin >> GameVariables.seed;
            if (std::cin.fail()) {
                menuFail();
            }
        }
        GameVariables.width = 100;
        GameVariables.height = 50;
        Game::generateWord();
}
