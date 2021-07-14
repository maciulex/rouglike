#include "../headers/player.h"
#include "../headers/game.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

extern bool ProgramOpenState;
extern int InputOutputDirection;

void Player::updateHP(int x) {
    char blockChar = 254;
    variables.health += x;
    int hp1=0,hp2=0,hpM1=0,hpM2=0;
    for (int i = 0; i < variables.maxHealth; i++) {
        if (i < 5) {
            if (i < variables.health) {
                hp1++;
            } else {
                hpM1++;
            }
        } else {
            if (i < variables.health) {
                hp2++;
            } else {
                hpM2++;
            }
        }
    }
    variables.healthString[0] = string(hp1, blockChar);
    variables.healthString[1] = string(hpM1, blockChar)+string(5-hp1-hpM1,32);
    variables.healthString[2] = string(hp2, blockChar);
    variables.healthString[3] = string(hpM2, blockChar)+string(5-hp2-hpM2,32);
};
void Player::updateMP(int x) {
    char blockChar = 254;
    variables.mana += x;
    int mp1=0,mp2=0,mpM1=0,mpM2=0;
    for (int i = 0; i < variables.maxMana; i++) {
        if (i < 5) {
            if (i < variables.mana) {
                mp1++;
            } else {
                mpM1++;
            }
        } else {
            if (i < variables.mana) {
                mp2++;
            } else {
                mpM2++;
            }
        }
    }
    variables.manaString[0] = string(mp1, blockChar);
    variables.manaString[1] = string(mpM1, blockChar)+string(5-mp1-mpM1,32);
    variables.manaString[2] = string(mp2, blockChar);
    variables.manaString[3] = string(mpM2, blockChar)+string(5-mp2-mpM2,32);
};
void Player::updateST(int x) {
    variables.strenge += x;
    variables.strengeString = to_string(variables.strenge)+string(5-to_string(variables.strenge).length(),32);
};
void Player::updateSP(int x) {
    variables.speed += x;
    variables.speedString = to_string(variables.speed)+string(5-to_string(variables.speed).length(),32);
};
void Player::updateIT(int x) {
    variables.itelligence += x;
    variables.itelligenceString = to_string(variables.itelligence)+string(5-to_string(variables.itelligence).length(),32);
};
void Player::updateCOIN(int x) {
    variables.coins += x;
    variables.coinsString = to_string(variables.coins)+string(5-to_string(variables.coins).length(),32);
};
void Player::updateVision(int x) {
    variables.eyes += x;
}

void Player::playerMove(int GoTox, int GoToy, bool draw) {
    if (MainGame::getData::getDataInBattle()) {
        return;
    }
    for (int i = 0; i < 150; i++) {
        if (variables.specialStatus[i][0] != -1) {
            variables.specialStatus[i][1]-=1;
            if (variables.specialStatus[i][1] == 0) {
                variables.specialStatus[i][0] = -1;
                restoreBlockedStatuses(variables.specialStatus[i][1]);
            }
        }
    }
    int cordinates[2] = {variables.y,variables.x};
    int hitStrenght = 0;
    if (GoTox < 0) {
        for (int i = 0; i > GoTox; i--) {
            int place = MainGame::getData::getDataBoard(cordinates[0],cordinates[1]-1);
            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
                cordinates[1] -= 1;
            } else {
                hitStrenght += 1;
                if (hitStrenght == 2 || place != -1 || place != -2) {
                    break;
                }
            }
        }
    } else if (GoTox > 0) {
        for (int i = 0; i < GoTox; i++) {
            int place = MainGame::getData::getDataBoard(cordinates[0],cordinates[1]+1);
            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
                cordinates[1] += 1;
            } else {
                hitStrenght += 1;
                if (hitStrenght == 2 || place != -1 || place != -2) {
                    break;
                }
            }
        }
    }
    if (GoToy < 0) {
        for (int i = 0; i > GoToy; i--) {
            int place = MainGame::getData::getDataBoard(cordinates[0]-1,cordinates[1]);
            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
                cordinates[0] -= 1;
            } else {
                hitStrenght += 1;
                if (hitStrenght == 2 || place != -1 || place != -2) {
                    break;
                }
            }
        }
    } else if (GoToy > 0) {
        for (int i = 0; i < GoToy; i++) {
            int place = MainGame::getData::getDataBoard(cordinates[0]+1,cordinates[1]);
            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
                cordinates[0] += 1;
            } else {
                hitStrenght += 1;
                if (hitStrenght == 2 || place != -1 || place != -2) {
                    break;
                }
            }
        }
    }
    variables.y = cordinates[0];
    variables.x = cordinates[1];
    if (MainGame::getData::getDataBoard(variables.y,variables.x) == 2) {
        MainGame::getData::setSpecialMessages("[i] dostepna komenda \"otworz\"",4);
    }
    switch (hitStrenght) {
        case 1:
            MainGame::getData::setSpecialMessages("Uderzasz glowa w mur!",0);
            hitWall(1);
        break;
        case 2:
            MainGame::getData::setSpecialMessages("Uderzasz z rozpedu w sciane",0);
            hitWall(2);
        break;
    }
//    if (rand()%100+1 > chanceForFight) {
//        drawGame();
//    } else {
//        CreateMonster();
//        cout << "Walka!";
//    }
    if (draw) {
        MainGame::drawGame();
    }
};
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
    int freeIndex, randomCase = 8;
    float rarity = (MainGame::getData::getLevel())*(MainGame::getData::getDifficulty())+(rand()%4*.5);
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
                    MainGame::getData::setSpecialMessages("Rozwaliles sobie leb -1hp pernamentnie", 1);
                    updateHP(-1);
                break;
                case 2:
                    MainGame::getData::setSpecialMessages("Cegla spadla ci na noge -2 predkosci na 2 tury", 1);
                    variables.specialStatus[freeIndex][0] = 14;
                    variables.specialStatus[freeIndex][1] = 2;
                    updateSP(-2);
                break;
                case 3:
                    MainGame::getData::setSpecialMessages("Uderzyles o sciane maly palec u nogi cie boli -1 speed na 3 tury", 1);
                    variables.specialStatus[freeIndex][0] = 13;
                    variables.specialStatus[freeIndex][1] = 3;
                    updateSP(-1);
                break;
                case 4:
                    MainGame::getData::setSpecialMessages("Uderzyles glowa o sciane -2 int na 3 tury", 1);
                    variables.specialStatus[freeIndex][0] = 11;
                    variables.specialStatus[freeIndex][1] = 3;
                    updateIT(-2);
                break;
                case 5:
                    MainGame::getData::setSpecialMessages("Prawie spadles z klifu ale zlapales sie reka -2 sily na 2 tury", 1);
                    variables.specialStatus[freeIndex][0] = 8;
                    variables.specialStatus[freeIndex][1] = 2;
                    updateST(-2);
                break;
                case 6:
                    MainGame::getData::setSpecialMessages("Uderzajac w sciane kamien z sufitu prawie zmiazdzyl ci glowe uzyles zaklecia i ocalales -2mp pernamentnie", 1);
                    updateMP(-2);
                break;
                case 7:
                    MainGame::getData::setSpecialMessages("Uderzajac w sciane zlamales palca u nogi -1 speed pernamentnie", 1);
                    updateSP(-1);
                break;
                case 8:
                    MainGame::getData::setSpecialMessages("Uderzajc w sciane znalazels ukryty zwoj", 1);
                    if (inventoryIndex == -1) {
                        MainGame::DrawBlank();
                        drawInventory();
                        cout << "------------------------------------------------------"
                        <<      "Potrzebujesz miejsca w ekwipunku by podniesc przedmiot"
                        <<      "------------------------------------------------------";
                    }
                    if (rarity < 1.5) {
                        MainGame::getData::setSpecialMessages("Zwoj walki skrawek", 2);
                    } else if (rarity < 3) {
                        MainGame::getData::setSpecialMessages("Zwoj walki maly", 2);
                    } else if (rarity < 6) {
                        MainGame::getData::setSpecialMessages("Zwoj walki sredni", 2);
                    } else if (rarity < 15) {
                        MainGame::getData::setSpecialMessages("Zwoj walki wielki", 2);
                    } else {
                        MainGame::getData::setSpecialMessages("Zwoj walki Legendarny", 2);
                    }
                break;
                case 9:
                    MainGame::getData::setSpecialMessages("Uderzajc w sciane znalazles ukryty skarb +200 monet", 1);
                    updateCOIN(200);
                break;
                case 10:
                    MainGame::getData::setSpecialMessages("Uderzajc w sciane znalazels ukryty zwoj +1 zwoj magiczny", 1);
                break;
            }
        break;
    }
}

int Player::getInventoryFreeIndex() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i] == -1) {
            return i;
        }
    }
    return -1;
}

void Player::drawInventory() {
    for (int i = 0; i < variables.inventorySize; i++) {
        if (variables.inventory[i] == -1) {
            cout << i+1 <<") Pusty Slot" << endl;
        } else {

        }
    }
}

Player::Player() {
    variables.maxHealth = 5;
    variables.maxMana = 3;
    variables.inventorySize = 50;
    updateHP(5);
    updateMP(3);
    updateSP(10);
    updateST(10);
    updateIT(3);
    variables.attacksMagican[0][0] = 1;
    variables.attacksMagican[1][0] = 2;
    variables.attacksMagican[2][0] = 3;
    variables.attacksWarrior[0][0] = 1;
    variables.attacksWarrior[1][0] = 2;
    variables.attacksWarrior[2][0] = 3;
}
