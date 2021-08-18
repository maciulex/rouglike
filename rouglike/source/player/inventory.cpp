#include "../../headers/player.hpp"

#include "../../headers/global.hpp"
#include "../../headers/utilitis/items.hpp"
#include "../../headers/utilitis/board.hpp"
#include "../../headers/utilitis/hud.hpp"
#include <iostream>
#include <math.h>

int Player::getInventoryFreeIndex() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i][0] == -1) {
            return i;
        }
    }
    return -1;
}

void Player::drawInventory() {
    for (int i = ((variables.actualPage-1)*25); i < (variables.actualPage*25); i++) {
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
    std::cout << "Strona: " << variables.actualPage << ", Z: " << ceil(variables.inventorySize/variables.inventoryOnePageItemAmount) << std::endl;
}

void Player::dropItemForNewOne_draw_only() {
    Board::drawBlank();
    drawInventory();
    std::cout << std::endl << "\t\t------------------------------------------------------"
    << std::endl <<           "\t\tPotrzebujesz miejsca w ekwipunku by podniesc przedmiot"
    << std::endl <<           "\t\t------------------------------------------------------" << std::endl << std::endl;
    Hud::drawHud();
}

void Player::dropItemForNewOne() {
    std::string choice;
    bool functionLoopState = true;
    GameVariables.hud = 2;
    while (functionLoopState) {
        dropItemForNewOne_draw_only();
        std::cin >> choice;
        switch (std::hash<std::string>{}(choice)) {

            case 14526079891305879776:
//           >
                if (variables.actualPage == ceil(variables.inventorySize/variables.inventoryOnePageItemAmount)) continue;
                variables.actualPage += 1;
            break;
            case 1396094175042499165:
//           <
                if (variables.actualPage == 1) continue;
                variables.actualPage -= 1;
            break;
            case 5772833367524736768:
//           powrot
                GameVariables.hud = 0;
                functionLoopState = false;
            break;
        }

    }
}
