#include "../headers/player.hpp"
#include "../headers/game.hpp"
#include "../headers/global.hpp"
#include "../headers/utilitis/board.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Player::PlayerVariables variablesPlayer;

Player::Player() {
    variablesPlayer.maxHealth = 5;
    variablesPlayer.maxMana = 3;
    variablesPlayer.inventorySize = 50;
    updateHP(5);
    updateMP(3);
    updateSP(10);
    updateST(10);
    updateIT(3);
    variablesPlayer.attacksMagican[0] = 1;
    variablesPlayer.attacksMagican[1] = 2;
    variablesPlayer.attacksMagican[2] = 3;
    variablesPlayer.attacksWarrior[0] = 1;
    variablesPlayer.attacksWarrior[1] = 2;
    variablesPlayer.attacksWarrior[2] = 3;
    variablesPlayer.inventory[0][0] = 0;
    variablesPlayer.inventory[0][1] = 0;
    variablesPlayer.inventory[1][0] = 0;
    variablesPlayer.inventory[1][1] = 1;
    for (int i = 2; i < 150; i++) {
        variablesPlayer.inventory[i][0] = -1;
        variablesPlayer.inventory[i][1] = -1;
        variablesPlayer.specialStatus[i][0] = -1;
        variablesPlayer.specialStatus[i][1] = -1;
    }
    for (int i = 0; i < 50; i++) {
        variablesPlayer.attacksWarrior[i] = -1;
        variablesPlayer.attacksMagican[i] = -1;
    }
    variablesPlayer.attacksWarrior[0] = 0;
    variablesPlayer.attacksWarrior[1] = 1;
}

void Player::hitWall(int strength) {
    char choice;
    int freeIndex = specialStatusFreeIndex(), randomCase = 8;
    float rarity = Game::getRarity();
    int inventoryIndex = getInventoryFreeIndex();
    //randomCase = rand();
    switch (strength) {
        case 1:
            switch (randomCase) {
                case 1:
                    Game::setSpecialMessages("Rozwaliles sobie leb -1hp pernamentnie", 1);
                    updateHP(-1);
                break;
                case 2:
                    Game::setSpecialMessages("Cegla spadla ci na noge -2 predkosci na 2 tury", 1);
                    variablesPlayer.specialStatus[freeIndex][0] = 14;
                    variablesPlayer.specialStatus[freeIndex][1] = 2;
                    updateSP(-2);
                break;
                case 3:
                    Game::setSpecialMessages("Uderzyles o sciane maly palec u nogi cie boli -1 speed na 3 tury", 1);
                    variablesPlayer.specialStatus[freeIndex][0] = 13;
                    variablesPlayer.specialStatus[freeIndex][1] = 3;
                    updateSP(-1);
                break;
                case 4:
                    Game::setSpecialMessages("Uderzyles glowa o sciane -2 int na 3 tury", 1);
                    variablesPlayer.specialStatus[freeIndex][0] = 11;
                    variablesPlayer.specialStatus[freeIndex][1] = 3;
                    updateIT(-2);
                break;
                case 5:
                    Game::setSpecialMessages("Prawie spadles z klifu ale zlapales sie reka -2 sily na 2 tury", 1);
                    variablesPlayer.specialStatus[freeIndex][0] = 8;
                    variablesPlayer.specialStatus[freeIndex][1] = 2;
                    updateST(-2);
                break;
                case 6:
                    Game::setSpecialMessages("Uderzajac w sciane kamien z sufitu prawie zmiazdzyl ci glowe uzyles zaklecia i ocalales -2mp pernamentnie", 1);
                    updateMP(-2);
                break;
                case 7:
                    Game::setSpecialMessages("Uderzajac w sciane zlamales palca u nogi -1 speed pernamentnie", 1);
                    updateSP(-1);
                break;
                case 8:
                    Game::setSpecialMessages("Uderzajc w sciane znalazels ukryty zwoj", 1);
                    if (rarity < 1.5) {
                        Game::setSpecialMessages("Zwoj walki skrawek", 2);
                    } else if (rarity < 3) {
                        Game::setSpecialMessages("Zwoj walki maly", 2);
                    } else if (rarity < 6) {
                        Game::setSpecialMessages("Zwoj walki sredni", 2);
                    } else if (rarity < 15) {
                        Game::setSpecialMessages("Zwoj walki wielki", 2);
                    } else {
                        Game::setSpecialMessages("Zwoj walki Legendarny", 2);
                    }
                    Board::drawGame();
                    cout << "Czy chcesz ten item? (T/N)";
                    cin >> choice;
                    BlockInputThread = true;
                    if (choice == 't' || choice == 'T') {
                        if (inventoryIndex == -1) {
                            dropItemForNewOne();
                        }
                        freeIndex = getInventoryFreeIndex();
                        if (inventoryIndex != -1) {
                            //do stuff adding item
                        }
                    }
                    BlockInputThread = false;
                break;
                case 9:
                    Game::setSpecialMessages("Uderzajc w sciane znalazles ukryty skarb +200 monet", 1);
                    updateCOIN(200);
                break;
                case 10:
                    Game::setSpecialMessages("Uderzajc w sciane znalazels ukryty zwoj +1 zwoj magiczny", 1);
                break;
            }
        break;
    }
}
int Player::specialStatusFreeIndex() {
    for (int i = 0; i < 150; i++) {
        if (variablesPlayer.specialStatus[i][0] == -1) {
            return i;
        }
    }
    return -1;
}

bool Player::isWeaponFromInventory(int index) {
    if (variablesPlayer.inventory[index][1] == 0 || variablesPlayer.inventory[index][1] == 1) return true;
    return false;
}

void Player::restoreBlockedStatuses(int which) {
    switch(which) {
        case 1:
            updateHP(1);
        break;
        case 2:
            updateHP(2);
        break;
        case 3:
            updateHP(3);
        break;
        case 4:
            updateMP(1);
        break;
        case 5:
            updateMP(2);
        break;
        case 6:
            updateMP(3);
        break;
        case 7:
            updateST(1);
        break;
        case 8:
            updateST(2);
        break;
        case 9:
            updateST(3);
        break;
        case 10:
            updateIT(1);
        break;
        case 11:
            updateIT(2);
        break;
        case 12:
            updateIT(3);
        break;
        case 13:
            updateSP(1);
        break;
        case 14:
            updateSP(2);
        break;
        case 15:
            updateSP(3);
        break;
        case 101:
            updateHP(-1);
        break;
        case 102:
            updateHP(-2);
        break;
        case 103:
            updateHP(-3);
        break;
        case 104:
            updateMP(-1);
        break;
        case 105:
            updateMP(-2);
        break;
        case 106:
            updateMP(-3);
        break;
        case 107:
            updateST(-1);
        break;
        case 108:
            updateST(-2);
        break;
        case 109:
            updateST(-3);
        break;
        case 110:
            updateIT(-1);
        break;
        case 111:
            updateIT(-2);
        break;
        case 112:
            updateIT(-3);
        break;
        case 113:
            updateSP(-1);
        break;
        case 114:
            updateSP(-2);
        break;
        case 115:
            updateSP(-3);
        break;
    }
}





