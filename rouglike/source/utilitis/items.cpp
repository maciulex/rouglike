#include "../../headers/utilitis/items.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

int indexMeleeWeapons;
int indexRangeWeapons;

gameItems::MeleeWeapon *MeleeWeaponArray;
gameItems::RangeWeapon *RangeWeaponArray;

void gameItems::loadWeapons() {
    indexMeleeWeapons = 0;
    indexRangeWeapons = 0;
    bool required[11] = {false};
    int goodItems = 0, failedItems = 0, totalIteams = 0;
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
    file.open("weapons.txt", std::ios::in);
    if (!file.good()) {
       std::cout << "\n\nBrak pliku z bronmi!" << std::endl;
       system("pause");
       exit(69);
    }
    while(std::getline(file, line)) {
        if (line[0] == '-') totalIteams += 1;
        else continue;
    }
    MeleeWeaponArray = new MeleeWeapon [totalIteams];
    RangeWeaponArray = new RangeWeapon [totalIteams];
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
void gameItems::addWeapon(std::string data[11]) {
    std::cout << "Item Loaded: " << data[8] << std::endl;
//    std::cout << std::endl << data[0] << std::endl << data[1] << std::endl << data[2] << std::endl << data[3] << std::endl << data[4] << std::endl << data[5]
//    << std::endl << data[6] << std::endl << data[7] << std::endl << data[8] << std::endl << data[9] << std::endl << data[10];

    int id = std::stoi(data[0]), classificationInt = std::stoi(data[5]), rarity=std::stoi(data[10]);
    std::string type = data[1], name = data[8], classification = data[9];
    float damage = std::stof(data[2]), speed = std::stof(data[3]), range = std::stof(data[4]), requiredStrength = std::stof(data[6]), requiredIteligence = std::stof(data[7]);
    switch (classificationInt) {
        case 1:
            MeleeWeaponArray[indexMeleeWeapons] = MeleeWeapon(id, damage, speed, range, classificationInt, requiredStrength, rarity, name, classification);
            indexMeleeWeapons += 1;
        break;
        case 2:
            RangeWeaponArray[indexRangeWeapons] = RangeWeapon(id, damage, speed, range, classificationInt, requiredIteligence, rarity, name, classification);
            indexRangeWeapons += 1;
        break;
    }
}

void gameItems::drawItems(int whichType) {
    if (whichType == 0) drawMelee();
    else if (whichType == 1) drawRange();
    else {
        drawMelee();
        drawRange();
    }
    std::cout << "By zobaczyc wiecej informacji wpisz \"showIteam |typ| |id|\"";
}

std::string gameItems::getWeaponData(int type, int id, std::string what) {
    switch (type) {
        case 0:
            return getMeleeData(id, what);
        case 1:
            return getRangeData(id, what);
    }
}

