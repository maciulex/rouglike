#include "../../../headers/debug/debug.hpp"
#include "../../../headers/utilitis/items.hpp"
#include <iostream>

void Debug::itemsSubMenu() {
    while (itemsSubMenuContent());
}
bool Debug::itemsSubMenuContent() {
    int choice;

    std::cout << std::endl
    << "--------Menu items--------" << std::endl
    << "\t1) load iteams" << std::endl
    << "\t2) show items"  << std::endl
    << "\t0) back"        << std::endl;

    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        itemsSubMenu();
    }
    switch (choice) {
        case 0:
            return false;
        case 1:
            gameItems::loadWeapons();
        break;
        case 2:
            std::cout      << std::endl << std::endl
            << "Which?"    << std::endl
            << "1) melee"  << std::endl
            << "2) range"  << std::endl
            << "3) all"    << std::endl
            << "0) cancel" << std::endl;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    gameItems::drawItems(0);
                break;
                case 2:
                    gameItems::drawItems(1);
                break;
                case 3:
                    gameItems::drawItems(2);
                break;
            }
        break;
    }
    return true;
}
