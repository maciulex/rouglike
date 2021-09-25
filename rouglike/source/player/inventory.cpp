#include "../../headers/player.hpp"

#include "../../headers/global.hpp"
#include "../../headers/utilitis/items.hpp"
#include "../../headers/utilitis/board.hpp"
#include "../../headers/utilitis/hud.hpp"
#include <iostream>
#include <math.h>


extern gameItems::MeleeWeapon *MeleeWeaponArray;
extern gameItems::RangeWeapon *RangeWeaponArray;
extern Player::PlayerVariables variablesPlayer;

int Player::getInventoryFreeIndex() {
    for (int i = 0; i < variablesPlayer.inventorySize; i++) {
        if (variablesPlayer.inventory[i][0] == -1) {
            return i;
        }
    }
    return -1;
}

void Player::drawInventory() {
    //variablesPlayer.equipedIteamId = 0;
    std::cout
    << "------------------------------------\n"
    << "\tAktualnie uzywany item: \n"
    << "\t" << getAcutalUseItemName() << "\n"
    << "------------------------------------\n";

    for (int i = ((variablesPlayer.actualPage-1)*25); i < (variablesPlayer.actualPage*25); i++) {
        if (variablesPlayer.inventory[i][0] == -1) {
            std::cout << "\t" << i+1 << ") Pusty Slot" << std::endl;
        } else {
            switch (variablesPlayer.inventory[i][1]) {
                case 0:
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(0, variablesPlayer.inventory[i][0], "name") << std::endl;
                break;
                case 1:
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(1, variablesPlayer.inventory[i][0], "name") << std::endl;
                break;
                case 2:
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(2, variablesPlayer.inventory[i][0], "name") << std::endl;
                break;
                case 3:
                    std::cout << "\t" << i+1 << ") " << gameItems::getItemData(3, variablesPlayer.inventory[i][0], "name") << std::endl;
                break;
                default:
                    std::cout << "\t" << i+1 << ") error" << std::endl;
                break;
            }
        }
    }
    std::cout << "Strona: " << variablesPlayer.actualPage << ", Z: " << ceil(variablesPlayer.inventorySize/variablesPlayer.inventoryOnePageItemAmount) << std::endl;
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
                if (choicedIteam < 1 || choicedIteam > variablesPlayer.inventorySize) continue;
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
                if (variablesPlayer.actualPage == ceil(variablesPlayer.inventorySize/variablesPlayer.inventoryOnePageItemAmount)) continue;
                variablesPlayer.actualPage += 1;
            break;
            case 1396094175042499165:
//              <
                if (variablesPlayer.actualPage == 1) continue;
                variablesPlayer.actualPage -= 1;
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
    switch (variablesPlayer.inventory[index][1]) {
        case 0:
            gameItems::drawMoreDataAboutMelee(variablesPlayer.inventory[index][0]);
        break;
        case 1:
            gameItems::drawMoreDataAboutRange(variablesPlayer.inventory[index][0]);
        break;
        case 2:
            gameItems::drawMoreDataAboutHeal(variablesPlayer.inventory[index][0]);
        break;
        case 3:
            gameItems::drawMoreDataAboutBuff(variablesPlayer.inventory[index][0]);
        break;
    }
}


void Player::dropIteam(int index) {
    if (iteamIndexValidation(index)) return;
    variablesPlayer.inventory[index][0] = -1;
    variablesPlayer.inventory[index][1] = -1;
}
void Player::dropIteam(std::string index) {
    int choicedIteam;
    if (index == "") return;
    choicedIteam = std::stoi(index)-1;
    if (iteamIndexValidation(choicedIteam)) return;
    variablesPlayer.inventory[choicedIteam][0] = -1;
    variablesPlayer.inventory[choicedIteam][1] = -1;
}
bool Player::iteamIndexValidation(int index) {
    return (index < 0 || index >= variablesPlayer.inventorySize);
}
bool Player::tryUseIteam(int index) {
    index -= 1;
    if (isWeaponFromInventory(index)) variablesPlayer.equipedIteamId = index;
    std::string useAble = gameItems::getItemData(variablesPlayer.inventory[index][1], variablesPlayer.inventory[index][0], "useable");
    if (useAble == "0" || useAble == "-1") return false;

    std::string rawEffects[2]        = {gameItems::getItemData(variablesPlayer.inventory[index][1], variablesPlayer.inventory[index][0], "effect"),
                                       gameItems::getItemData(variablesPlayer.inventory[index][1], variablesPlayer.inventory[index][0], "optional_effect")};
    std::string effect, effectLatency;
    bool effectPernament = true;
    for (int i = 0; i < 2; i++) {
        try {
            for (int x = 0; x < rawEffects[i].length(); x++) {
                if (rawEffects[i][x] == ',') {
                    effectPernament = false;
                    continue;
                } else if (rawEffects[i][x] == '|') {
                    if (effectPernament) finalizeEffect(std::stoi(effect));
                    else finalizeEffect(std::stoi(effect), effectPernament, std::stoi(effectLatency));
                    effect = "";
                    effectLatency = "";
                    effectPernament = true;
                    continue;
                }
                if (effectPernament) effect += rawEffects[i][x];
                else effectLatency += rawEffects[i][x];
            }
        } catch (_exception &e) {
            std::cout << std::endl << "Pewien efekt nie zadzialal ):" << std::endl;
        }
    }
}
void Player::finalizeEffect(int effect, bool pernament, int latency) {
    restoreBlockedStatuses(effect);
    if (!pernament) {
        int freeIndex = specialStatusFreeIndex();
        if (freeIndex == -1) return;
        variablesPlayer.specialStatus[freeIndex][1] = latency;
        if (effect < 100) variablesPlayer.specialStatus[freeIndex][0] = effect+100;
        else variablesPlayer.specialStatus[freeIndex][0] = effect-100;
    }
}

std::string Player::getAcutalUseItemName() {
    if (variablesPlayer.equipedIteamId == -1 || variablesPlayer.inventory[variablesPlayer.equipedIteamId][1] == -1 || variablesPlayer.inventory[variablesPlayer.equipedIteamId][0] == -1) return "Nic nie jest zekwipowane";
    return gameItems::getItemData(variablesPlayer.inventory[variablesPlayer.equipedIteamId][1], variablesPlayer.inventory[variablesPlayer.equipedIteamId][0], "name");
}


