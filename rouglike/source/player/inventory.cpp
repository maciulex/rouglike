#include "../../headers/player.hpp"

#include "../../headers/utilitis/items.hpp"

#include <iostream>


int Player::getInventoryFreeIndex() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i][0] == -1) {
            return i;
        }
    }
    return -1;
}

void Player::drawInventory() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i][0] == -1) {
            std::cout << "\t" << i+1 << ") Pusty Slot" << std::endl;
        } else {
            switch (variables.inventory[i][1]) {
                case 0:
                    std::cout << "\t" << i+1 << ") " << gameItems::getWeaponData(0, variables.inventory[i][0], "name") << std::endl;
                break;
                case 1:
                    std::cout << "\t" << i+1 << ") " << gameItems::getWeaponData(1, variables.inventory[i][0], "name") << std::endl;
                break;
                default:
                    std::cout << "\t" << i+1 << ") error" << std::endl;
                break;
            }
        }
    }
}

void Player::dropItemForNewOne() {
    BlockInputThread = true;
    Board::drawBlank();
    drawInventory();
    GameVariables.hud = 2;
    cout << endl << "------------------------------------------------------"
    <<              "Potrzebujesz miejsca w ekwipunku by podniesc przedmiot"
    <<              "------------------------------------------------------";

    BlockInputThread = false;
}
