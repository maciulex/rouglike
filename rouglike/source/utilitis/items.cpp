#include "../../headers/utilitis/items.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

int indexMeleeWeapons;
int indexRangeWeapons;
int indexHealWeapons;
int indexBuffWeapons;

gameItems::MeleeWeapon *MeleeWeaponArray;
gameItems::RangeWeapon *RangeWeaponArray;
gameItems::HealPotion  *HealPotionArray;
gameItems::BuffPotion  *BuffPotionArray;


void gameItems::loadIteams() {
    gameItems::loadOther();
    loadWeapons();
}

void gameItems::loadOther() {
    std::cout << "Ladowanie innych" << std::endl;
    indexHealWeapons = 0;
    indexBuffWeapons = 0;
    bool required[9] = {false};
    int goodItems = 0, failedItems = 0, totalIteams = 0, healWeapons = 0, buffWeapons = 0;
    std::string line, data[10];

    std::unordered_map<std::string, int> typeNameId = {
        {"id", 0},
        {"type", 1},
        {"classificationInt", 2},
        {"name", 3},
        {"classificationText", 4},
        {"lore", 5}
    };
    std::unordered_map<std::string, int> notRequiredData = {
        {"buff", 6},
        {"base_effect", 7},
        {"optional_effect", 8},
        {"rarity", 9}
    };
    std::fstream file;
    file.open("data/otherIteams.txt", std::ios::in);
    if (!file.good()) {
       std::cout << "\n\nBrak pliku z innymi przedmiotami!" << std::endl;
       system("pause");
       exit(69);
    }
    while(std::getline(file, line)) {
        if (line[0] == '-') {
            totalIteams += 1;
            if (line[1] == '3') {
                healWeapons += 1;
            } else if (line[1] == '4'){
                buffWeapons += 1;
            }
        }
        else continue;
    }
    HealPotionArray = new HealPotion [healWeapons];
    BuffPotionArray = new BuffPotion [buffWeapons];
    file.clear();
    file.seekg(0);
    while(std::getline(file, line)) {
        if (line == "" || line[0] == ' ') continue;
        bool secondPart = false;
        std::string actualLineType = "", actualLineContent = "";
        //checking at end
        if (line[0] == '-') {
            bool fail = false;
            for (int i = 0; i < typeNameId.size(); i++) {
                if (required[i] != false) continue;
                fail = true;
                break;
            }
            if (fail) {
                failedItems+=1;
            } else {
                goodItems+=1;
                addOther(data);
            }
            continue;
        }
        //getting data
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ':') {
                secondPart = true;
                continue;
            }
            if (!secondPart) actualLineType += line[i];
            else actualLineContent += line[i];
        }
        //std::cout << actualLineType << std::endl;
        if (typeNameId.find(actualLineType) != typeNameId.end()) {
            required[typeNameId.at(actualLineType)] = true;
            data[typeNameId.at(actualLineType)] = actualLineContent;
        } else {
            data[notRequiredData.at(actualLineType)] = actualLineContent;
        }

    }
    std::cout << std::endl << std::endl
    << "Udane itemy: " << goodItems << std::endl
    << "Fail itemy: " << failedItems << std::endl
    << "Wszystkie itemy: "<< totalIteams << std::endl
    << std::endl;
    file.close();
}

void gameItems::loadWeapons() {
    std::cout << "Ladowanie broni" << std::endl;
    indexMeleeWeapons = 0;
    indexRangeWeapons = 0;
    bool required[11] = {false};
    int goodItems = 0, failedItems = 0, totalIteams = 0, meleeWeapons = 0, rangeWeapons = 0;
    std::string line, data[11];

    std::unordered_map<std::string, int> typeNameId = {
        {"id", 0},
        {"type", 1},
        {"damage", 2},
        {"speed", 3},
        {"range", 4},
        {"classificationInt", 5},
        {"requiredStrenght", 6},
        {"requiredItelligence", 7},
        {"name", 8},
        {"classificationText", 9},
        {"rarity", 10}
    };

    std::fstream file;
    file.open("data/weapons.txt", std::ios::in);
    if (!file.good()) {
       std::cout << "\n\nBrak pliku z bronmi!" << std::endl;
       system("pause");
       exit(69);
    }
    while(std::getline(file, line)) {
        if (line[0] == '-') {
            totalIteams += 1;
            if (line[1]=='1') {
                meleeWeapons += 1;
            } else if (line[1] == '2'){
                rangeWeapons += 1;
            }
        }
        else continue;
    }
    MeleeWeaponArray = new MeleeWeapon [meleeWeapons];
    RangeWeaponArray = new RangeWeapon [rangeWeapons];
    file.clear();
    file.seekg(0);
    while(std::getline(file, line)) {
        if (line == "" || line[0] == ' ') continue;
        bool secondPart = false;
        std::string actualLineType = "", actualLineContent = "";
        if (line[0] == '-') {
            bool fail = false;
            for (int i = 0; i < typeNameId.size(); i++) {
                if (required[i] != false) continue;
                fail = true;
                break;
            }
            if (fail) {
                failedItems+=1;
            } else {
                goodItems+=1;
                addWeapon(data);
            }
            continue;
        }
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ':') {
                secondPart = true;
                continue;
            }
            if (!secondPart) actualLineType += line[i];
            else actualLineContent += line[i];
        }
        //std::cout << actualLineType << " : ";
        required[typeNameId.at(actualLineType)] = true;

        data[typeNameId.at(actualLineType)] = actualLineContent;

    }
    std::cout << std::endl << std::endl
    << "Udane itemy: " << goodItems << std::endl
    << "Fail itemy: " << failedItems << std::endl
    << "Wszystkie itemy: "<< totalIteams << std::endl
    << std::endl;
    file.close();

}

void gameItems::addOther(std::string data[8]) {
    //std::cout << "Item Loaded: " << data[3] << std::endl;
//    std::cout << std::endl << data[0] << std::endl << data[1] << std::endl << data[2] << std::endl << data[3] << std::endl << data[4] << std::endl << data[5]
//    << std::endl << data[6] << std::endl << data[7] << std::endl << data[8] << std::endl << data[9] << std::endl << data[10];

    int id = std::stoi(data[0]), classificationInt = std::stoi(data[2]), rarity=std::stoi(data[9]);
    std::string type = data[1], name = data[3], classification = data[4], lore = data[5], buff = data[6], base_effect = data[7], optional_effect = data[8];

    switch (classificationInt) {
        case 3:
            HealPotionArray[indexHealWeapons] = HealPotion(id,base_effect,rarity,name,lore,classification,classificationInt,optional_effect);
            indexHealWeapons += 1;
        break;
        case 4:
            BuffPotionArray[indexBuffWeapons] = BuffPotion(id,buff,rarity,name,lore,classification,classificationInt,optional_effect);
            indexBuffWeapons += 1;
        break;
    }
}

void gameItems::addWeapon(std::string data[11]) {
    //std::cout << "Item Loaded: " << data[8] << std::endl;

    int id = std::stoi(data[0]), classificationInt = std::stoi(data[5]), rarity=std::stoi(data[10]);
    std::string type = data[1], name = data[8], classification = data[9];
    float damage = std::stof(data[2]), speed = std::stof(data[3]), range = std::stof(data[4]), requiredStrength = std::stof(data[6]), requiredIteligence = std::stof(data[7]);
    switch (classificationInt) {
        case 1:
            MeleeWeaponArray[indexMeleeWeapons] = MeleeWeapon(id, damage, speed, range, requiredStrength, rarity, name, classification, classificationInt);
            indexMeleeWeapons += 1;
        break;
        case 2:
            RangeWeaponArray[indexRangeWeapons] = RangeWeapon(id, damage, speed, range, requiredIteligence, rarity, name, classification, classificationInt);
            indexRangeWeapons += 1;
        break;
    }

}

void gameItems::drawItems(int whichType) {
    switch (whichType) {
        case 0:
            drawMelee();
        break;
        case 1:
            drawRange();
        break;
        case 2:
            drawHeal();
        break;
        case 3:
            drawBuff();
        break;
        default:
            drawMelee();
            drawRange();
            drawHeal();
            drawBuff();
        break;
    }
    std::cout << "By zobaczyc wiecej informacji wpisz \"showIteam |typ| |id|\"";
}

std::string gameItems::getItemData(int type, int id, std::string what) {
    switch (type) {
        case 0:
            return getMeleeData(id, what);
        case 1:
            return getRangeData(id, what);
        case 2:
            return getHealData(id, what);
        case 3:
            return getBuffData(id, what);
        default: return "-1";
    }
}


