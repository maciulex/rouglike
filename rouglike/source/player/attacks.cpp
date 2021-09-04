#include "../../headers/player.hpp"

#include "../../headers/utilitis/items.hpp"
#include "../../headers/fight/attacks.hpp"
#include <iostream>

extern Attacks::AttacksDataStruct AttacksData;

void Player::drawAttacksWarrior() {
    std::cout << "\n\n\n";
    for (int i = 49; i >= 0; i--) {
        if (variables.attacksWarrior[i] == -1) {
            std::cout << i+1 << ") Brak Ataku \n";
        } else {
            Attacks::MeleeAttack thisAttack = AttacksData.MeleeAttacksArray[variables.attacksWarrior[i]];
            std::cout << i+1 << ") " << thisAttack.getAttackBaseData("name") << "\n";
        }
    }
    std::cout << "0) Wroc";
}

void Player::drawAttacksMagican() {
    std::cout << "\n\n\n";
    for (int i = 49; i >= 0; i--) {
        if (variables.attacksMagican[i] == -1) {
            std::cout << i+1 << ") Brak Ataku \n";
        } else {
            Attacks::RangeAttack thisAttack = AttacksData.RangeAttacksArray[variables.attacksMagican[i]];
            std::cout << i+1 << ") " << thisAttack.getAttackBaseData("name") << "\n";
        }
    }
    std::cout << "0) Wroc";
}

int Player::getWarriorAttackFreeIndeks() {
    for (int i = 0; i < 50; i++) {
        if (variables.attacksWarrior[i] == -1) {
            return i;
        }
    }
    return -1;
}
int Player::getMagicanAttackFreeIndeks() {
    for (int i = 0; i < 50; i++) {
        if (variables.attacksMagican[i] == -1) {
            return i;
        }
    }
    return -1;
}



