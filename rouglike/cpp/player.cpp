#include "../headers/player.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

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
Player::Player() {
    variables.maxHealth = 5;
    variables.maxMana = 3;
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



