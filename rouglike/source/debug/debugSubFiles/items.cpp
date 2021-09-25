#include "../../../headers/debug/debug.hpp"
#include "../../../headers/utilitis/items.hpp"
#include "../../../headers/player.hpp"
#include <iostream>

extern Player player;
extern Player::PlayerVariables variablesPlayer;


void Debug::itemsSubMenu() {
    while (itemsSubMenuContent());
}
bool Debug::itemsSubMenuContent() {
    int choice;

    std::cout << std::endl
    << "--------Menu items--------" << std::endl
    << "\t1) load iteams" << std::endl
    << "\t2) show items"  << std::endl
    << "\t3) change item"  << std::endl
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
            << "3) heal"  << std::endl
            << "4) buff"  << std::endl
            << "5) all"    << std::endl
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
                case 4:
                    gameItems::drawItems(3);
                break;
                case 5:
                    gameItems::drawItems(4);
                break;

            }
        break;
        case 3:
            changeIteamInInventory();
        break;
    }
    return true;
}
void Debug::changeIteamInInventory() {
    int index, id_type, id_item;
    std::cout << "Index, id_type[0-3], id_iteam[0-?]" << std::endl;
    std::cin >> index >> id_type >> id_item;
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        return;
    }
    variablesPlayer.inventory[index][0] = id_item;
    variablesPlayer.inventory[index][1] = id_type;
}
