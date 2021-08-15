#include "../headers/player.hpp"
#include "../headers/game.hpp"
#include "../headers/global.hpp"
#include "../headers/utilitis/board.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player() {
    variables.maxHealth = 5;
    variables.maxMana = 3;
    variables.inventorySize = 50;
    updateHP(5);
    updateMP(3);
    updateSP(10);
    updateST(10);
    updateIT(3);
    variables.attacksMagican[0] = 1;
    variables.attacksMagican[1] = 2;
    variables.attacksMagican[2] = 3;
    variables.attacksWarrior[0] = 1;
    variables.attacksWarrior[1] = 2;
    variables.attacksWarrior[2] = 3;
}


void Player::restoreBlockedStatuses(int which) {
    switch(which) {
        case 7:
            updateST(1);
        case 10:
            updateMP(1);
        break;
        case 14:
            updateSP(2);
        break;
    }
}
void Player::hitWall(int strength) {
    char choice;
    int freeIndex, randomCase = 8;
    float rarity = Game::getRarity();
    int inventoryIndex = getInventoryFreeIndex();
    //randomCase = rand();
    for (int i = 0; i < 150; i++) {
        if (variables.specialStatus[i][0] == -1) {
            freeIndex = i;
        }
    }
    switch (strength) {
        case 1:
            switch (randomCase) {
                case 1:
                    Game::setSpecialMessages("Rozwaliles sobie leb -1hp pernamentnie", 1);
                    updateHP(-1);
                break;
                case 2:
                    Game::setSpecialMessages("Cegla spadla ci na noge -2 predkosci na 2 tury", 1);
                    variables.specialStatus[freeIndex][0] = 14;
                    variables.specialStatus[freeIndex][1] = 2;
                    updateSP(-2);
                break;
                case 3:
                    Game::setSpecialMessages("Uderzyles o sciane maly palec u nogi cie boli -1 speed na 3 tury", 1);
                    variables.specialStatus[freeIndex][0] = 13;
                    variables.specialStatus[freeIndex][1] = 3;
                    updateSP(-1);
                break;
                case 4:
                    Game::setSpecialMessages("Uderzyles glowa o sciane -2 int na 3 tury", 1);
                    variables.specialStatus[freeIndex][0] = 11;
                    variables.specialStatus[freeIndex][1] = 3;
                    updateIT(-2);
                break;
                case 5:
                    Game::setSpecialMessages("Prawie spadles z klifu ale zlapales sie reka -2 sily na 2 tury", 1);
                    variables.specialStatus[freeIndex][0] = 8;
                    variables.specialStatus[freeIndex][1] = 2;
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
                    if (choice == 't' || choice == 'T') {
                        if (inventoryIndex == -1) {
                            player.dropItemForNewOne();
                        }
                        freeIndex = player.getInventoryFreeIndex();
                        if (inventoryIndex != -1) {
                            //do stuff adding item
                        }
                    }
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





