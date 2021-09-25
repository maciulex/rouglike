#include "../../../headers/debug/debug.hpp"
#include "../../../headers/player.hpp"
#include <iostream>

extern Player player;
extern Player::PlayerVariables variablesPlayer;

void Debug::playerSubMenu() {
    while (playerSubMenuContent());
}
bool Debug::playerSubMenuContent() {
    int choice;

    std::cout << std::endl
    << "--------Menu player--------" << std::endl
    << "\t1) change player stats" << std::endl
    << "\t0) back"        << std::endl;

    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        playerSubMenuContent();
    }
    switch (choice) {
        case 0:
            return false;
        case 1:
            changeStatsMenu();
        break;
    }
    return true;
}

void Debug::changeStatsMenu() {
    int choice, amount;
    std::cout << std::endl
    << "--------Menu player, stats--------" << std::endl
    << "\t1) health" << std::endl
    << "\t2) mana" << std::endl
    << "\t3) strenght" << std::endl
    << "\t4) speed" << std::endl
    << "\t5) inteligention" << std::endl
    << "\t6) vission" << std::endl
    << "\t7) maxHp" << std::endl
    << "\t8) maxMp" << std::endl
    << "\t0) back"        << std::endl;

    std::cin >> choice;
    std::cout << std::endl << "How much? " << std::endl;
    std::cin >> amount;
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        playerSubMenuContent();
    }
    switch (choice) {
        case 0:
            return;
        case 1:
            player.updateHP(amount);
        break;
        case 2:
            player.updateMP(amount);
        break;
        case 3:
            player.updateST(amount);
        break;
        case 4:
            player.updateSP(amount);
        break;
        case 5:
            player.updateIT(amount);
        break;
        case 6:
            player.updateVision(amount);
        break;
        case 7:
            variablesPlayer.maxHealth += amount;
        break;
        case 8:
            variablesPlayer.maxMana += amount;
        break;
    }
}
