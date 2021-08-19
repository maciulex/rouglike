#include "../../headers/player.hpp"

#include "../../headers/global.hpp"
#include "../../headers/utilitis/items.hpp"
#include "../../headers/utilitis/board.hpp"
#include "../../headers/utilitis/hud.hpp"
#include <iostream>
#include <math.h>


extern gameItems::MeleeWeapon *MeleeWeaponArray;
extern gameItems::RangeWeapon *RangeWeaponArray;

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
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(0, variables.inventory[i][0], "name") << std::endl;
                break;
                case 1:
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(1, variables.inventory[i][0], "name") << std::endl;
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
    bool functionLoopState = true;
    GameVariables.hud = 2;
    while (functionLoopState) {
        std::string rawChoice;
        std::string choice[5] = {""};
        int commandIndex = 0;

        dropItemForNewOne_draw_only();

        std::getline(std::cin, rawChoice);

        for (int i = 0; i < rawChoice.length(); i++) {
            if (commandIndex == 5) break;
            if (rawChoice[i] == ' ') {
                commandIndex += 1;
                continue;
            }
            choice[commandIndex] += rawChoice[i];
        }
        int choicedIteam;
        switch (std::hash<std::string>{}(choice[0])) {
            case 5366797971342239317:
//              Szczegoly
                if (choice[1] == "") continue;
                choicedIteam = std::stoi(choice[1]);
                if (choicedIteam < 1 || choicedIteam > variables.inventorySize) continue;
                choicedIteam -= 1;
                drawMoreDataAbout(choicedIteam);
                system("pause");
            break;
            case 3260554669361923085:
//              Wyrzuc
                dropIteam(choice[1]);
            break;
            case 14526079891305879776:
//              >
                if (variables.actualPage == ceil(variables.inventorySize/variables.inventoryOnePageItemAmount)) continue;
                variables.actualPage += 1;
            break;
            case 1396094175042499165:
//              <
                if (variables.actualPage == 1) continue;
                variables.actualPage -= 1;
            break;
            case 5772833367524736768:
//              powrot
                GameVariables.hud = 0;
                functionLoopState = false;
            break;
        }

    }
}

void Player::drawMoreDataAbout(int index) {
    switch (variables.inventory[index][1]) {
        case 0:
            gameItems::drawMoreDataAboutMelee(variables.inventory[index][0]);
        break;
        case 1:
            gameItems::drawMoreDataAboutRange(variables.inventory[index][0]);
        break;
        case 2:
            gameItems::drawMoreDataAboutHeal(variables.inventory[index][0]);
        break;
        case 3:
            gameItems::drawMoreDataAboutBuff(variables.inventory[index][0]);
        break;
    }
}


void Player::dropIteam(int index) {
    if (iteamIndexValidation(index)) return;
    variables.inventory[index][0] = -1;
    variables.inventory[index][1] = -1;
}
void Player::dropIteam(std::string index) {
    int choicedIteam;
    if (index == "") return;
    choicedIteam = std::stoi(index)-1;
    if (iteamIndexValidation(choicedIteam)) return;
    variables.inventory[choicedIteam][0] = -1;
    variables.inventory[choicedIteam][1] = -1;
}
bool Player::iteamIndexValidation(int index) {
    return (index < 0 || index >= variables.inventorySize);
}
bool Player::tryUseIteam(int index) {
    if (gameItems::getItemData(variables.inventory[index][1], variables.inventory[index][0], "useable") == "0") return false;





}


