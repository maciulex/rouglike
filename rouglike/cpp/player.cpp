#include "../headers/player.h"
#include "../headers/game.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

extern bool ProgramOpenState;
extern int InputOutputDirection;
//extern struct MainGame::GameVariablesStruct GameVariables;

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
void Player::playerMove(int GoTox, int GoToy) {
//    if (MainGame::GameVariables.battle) {
//        return;
//    }
//    for (int i = 0; i < 150; i++) {
//        if (variables.specialStatus[i][0] != -1) {
//            variables.specialStatus[i][1]-=1;
//            if (variables.specialStatus[i][1] == 0) {
//                variables.specialStatus[i][0] = -1;
//                restoreBlockedStatuses(variables.specialStatus[i][1]);
//            }
//        }
//    }
//    int cordinates[2] = {variables.y,variables.x};
//    int hitStrenght = 0;
//    if (GoTox < 0) {
//        for (int i = 0; i > GoTox; i--) {
//            cout << MainGame::GameVariables.board[0][0];
//            //int place = MainGame::GameVariables.board[cordinates[0]][cordinates[1]-1];
//            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
//                cordinates[1] -= 1;
//            } else {
//                hitStrenght += 1;
//                if (hitStrenght == 2 || place != -1 && place != -2) {
//                    break;
//                }
//            }
//        }
//    } else if (GoTox > 0) {
//        for (int i = 0; i < GoTox; i++) {
//            int place = MainGame::GameVariables.board[cordinates[0]][cordinates[1]+1];
//            if (place != -1 && place != -2 && place != 1 && hitStrenght == 0) {
//                cordinates[1] += 1;
//            } else {
//                hitStrenght += 1;
//                if (hitStrenght == 2) {
//                    break;
//                }
//            }
//        }
//    }
//    variables.y += cordinates[0];
//    variables.x += cordinates[1];
//    if (MainGame::GameVariables.board[variables.y][variables.x] == 2) {
//        MainGame::GameVariables.specialMesseges[4] = "[i] dostepna komenda \"otworz\"";
//    }
//    switch (hitStrenght) {
//        case 1:
//            MainGame::GameVariables.specialMesseges[0] = "Uderzasz glowa w mur!";
//            hitWall(1);
//        break;
//        case 2:
//            MainGame::GameVariables.specialMesseges[0] = "Uderzasz z rozpedu w sciane";
//            hitWall(2);
//        break;
//    }
//    if (rand()%100+1 > chanceForFight) {
//        drawGame();
//    } else {
//        CreateMonster();
//        cout << "Walka!";
//    }
    MainGame::drawGame();
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

}
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
