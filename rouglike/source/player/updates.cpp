#include "../../headers/player.hpp"
#include "../../headers/game.hpp"
#include "../../headers/global.hpp"
#include "../../headers/utilitis/board.hpp"

#include <string>

using namespace std;

extern Player::PlayerVariables variablesPlayer;

void Player::playerMove(int GoTox, int GoToy, bool draw) {
    if (GameVariables.battle) {
        return;
    }
    for (int i = 0; i < 150; i++) {
        if (variablesPlayer.specialStatus[i][0] != -1) {
            variablesPlayer.specialStatus[i][1]-=1;
            if (variablesPlayer.specialStatus[i][1] == 0) {
                variablesPlayer.specialStatus[i][0] = -1;
                restoreBlockedStatuses(variablesPlayer.specialStatus[i][1]);
            }
        }
    }
    int cordinates[2] = {variablesPlayer.y,variablesPlayer.x};
    int hitStrenght = 0;
    if (GoTox < 0) {
        for (int i = 0; i > GoTox; i--) {
            int place = GameVariables.board[cordinates[0]][cordinates[1]-1];
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
            int place = GameVariables.board[cordinates[0]][cordinates[1]+1];
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
            int place = GameVariables.board[cordinates[0]-1][cordinates[1]];
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
            int place = GameVariables.board[cordinates[0]+1][cordinates[1]];
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
    variablesPlayer.y = cordinates[0];
    variablesPlayer.x = cordinates[1];
    if (GameVariables.board[variablesPlayer.y][variablesPlayer.x] == 2) {
        Game::setSpecialMessages("[i] dostepna komenda \"otworz\"",4);
    }
    switch (hitStrenght) {
        case 1:
            Game::setSpecialMessages("Uderzasz glowa w mur!",0);
            hitWall(1);
        break;
        case 2:
            Game::setSpecialMessages("Uderzasz z rozpedu w sciane",0);
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
        Board::drawGame();
    }
};

void Player::updateHP(int x) {
    char blockChar = 254;
    if (variablesPlayer.health+x <= variablesPlayer.maxHealth) variablesPlayer.health += x;
    else variablesPlayer.health = variablesPlayer.maxHealth;
    int hp1=0,hp2=0,hpM1=0,hpM2=0;
    for (int i = 0; i < variablesPlayer.maxHealth; i++) {
        if (i < 5) {
            if (i < variablesPlayer.health) {
                hp1++;
            } else {
                hpM1++;
            }
        } else {
            if (i < variablesPlayer.health) {
                hp2++;
            } else {
                hpM2++;
            }
        }
    }
    variablesPlayer.healthString[0] = string(hp1, blockChar);
    variablesPlayer.healthString[1] = string(hpM1, blockChar)+string(5-hp1-hpM1,32);
    variablesPlayer.healthString[2] = string(hp2, blockChar);
    variablesPlayer.healthString[3] = string(hpM2, blockChar)+string(5-hp2-hpM2,32);
};
void Player::updateMP(int x) {
    char blockChar = 254;
    if (variablesPlayer.mana+x <= variablesPlayer.maxMana) variablesPlayer.mana += x;
    else variablesPlayer.mana = variablesPlayer.maxMana;
    int mp1=0,mp2=0,mpM1=0,mpM2=0;
    for (int i = 0; i < variablesPlayer.maxMana; i++) {
        if (i < 5) {
            if (i < variablesPlayer.mana) {
                mp1++;
            } else {
                mpM1++;
            }
        } else {
            if (i < variablesPlayer.mana) {
                mp2++;
            } else {
                mpM2++;
            }
        }
    }
    variablesPlayer.manaString[0] = string(mp1, blockChar);
    variablesPlayer.manaString[1] = string(mpM1, blockChar)+string(5-mp1-mpM1,32);
    variablesPlayer.manaString[2] = string(mp2, blockChar);
    variablesPlayer.manaString[3] = string(mpM2, blockChar)+string(5-mp2-mpM2,32);
};
void Player::updateST(int x) {
    variablesPlayer.strenge += x;
    variablesPlayer.strengeString = to_string(variablesPlayer.strenge)+string(5-to_string(variablesPlayer.strenge).length(),32);
};
void Player::updateSP(int x) {
    variablesPlayer.speed += x;
    variablesPlayer.speedString = to_string(variablesPlayer.speed)+string(5-to_string(variablesPlayer.speed).length(), 32);
};
void Player::updateIT(int x) {
    variablesPlayer.itelligence += x;
    variablesPlayer.itelligenceString = to_string(variablesPlayer.itelligence)+string(5-to_string(variablesPlayer.itelligence).length(),32);
};
void Player::updateCOIN(int x) {
    variablesPlayer.coins += x;
    variablesPlayer.coinsString = to_string(variablesPlayer.coins)+string(5-to_string(variablesPlayer.coins).length(),32);
};
void Player::updateVision(int x) {
    variablesPlayer.eyes += x;
}

