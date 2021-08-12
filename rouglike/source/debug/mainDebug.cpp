#include "../../headers/debug/debug.hpp"
#include <iostream>


void Debug::debug() {
    while (menu());
}

bool Debug::menu() {
    int choice;
    std::cout << "\n--------MENU--------" << std::endl
    << "\t1) get hash code"  << std::endl
    << "\t2) items sub menu" << std::endl
    << "\t0) exit"           << std::endl;

    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.ignore(1000,'\n');
        menu();
    }
    switch (choice) {
        case 0:
            return false;
        case 1:
            getHashCode();
        break;
        case 2:
            itemsSubMenu();
        break;
        default:
            return true;
    }

}

void Debug::getHashCode() {
    std::string toHash;
    std::cout << "\nPodaj ciag ktory ma byc hashem" << std::endl;
    std::cin >> toHash;
    std::cout << std::hash<std::string>{}(toHash);
}
