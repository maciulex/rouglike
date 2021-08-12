#include "../../headers/player.hpp"

int Player::getInventoryFreeIndex() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i] == -1) {
            return i;
        }
    }
    return -1;
}

void Player::drawInventory() {
//    for (int i = 0; i < variables.inventorySize; i++) {
//        if (variables.inventory[i] == -1) {
//            cout << "\t" << i+1 << ") Pusty Slot" << endl;
//        } else {
//            cout << "\t" << i+1 << ") " << MeleeWeaponArrray[variables.inventory[i]].name << endl;
//        }
//    }
}
