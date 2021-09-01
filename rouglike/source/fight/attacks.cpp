#include "../../headers/fight/attacks.hpp"

#include <iostream>
#include <fstream>
#include <unordered_map>

Attacks::AttacksDataStruct AttacksData;

std::unordered_map<std::string, int> baseAttackConponentsId = {
    {"name",            0},
    {"lore",            1},
    {"lvl",             2},
    {"min_lvl",         3},
    {"rarity",          4},
    {"meleeDamage",     5},
    {"distanceDamage",  6},
    {"meleeDef",        7},
    {"distanceDef",     8},
    {"speed",           9},
    {"range",           10},
    {"chanceOfWork",    11},
    {"attackType",      12},
    {"costs",           13}
};

void Attacks::loadAttacks() {
    std::cout << std::endl << "Ladowanie atakow";

    loadAttacksMelee();
    loadAttacksRange();

    system("pause");
}

void Attacks::loadAttacksMelee() {
    int all = 0, good = 0, failed = 0;
    std::string dataLine = "", dataItem[20];

    std::cout << "\n\nLadowanie atakow wrecz \n";

    std::fstream file;
    file.open("data/attacksMelee.txt", std::ios::in);

    while (getline(file, dataLine)) {
        if (dataLine[0] == '-') all += 1;
    }

    file.clear();
    file.seekg(0);

    AttacksData.MeleeAttacksArray = new MeleeAttack [all];

    while (getline(file, dataLine)) {
        if (dataLine == "" || dataLine[0] == ' ') continue;
        if (dataLine[0] == '-') {
            addAttackMelee(dataItem);
            for (int i = 0; i < 20; i++) dataItem[i] = "";
        }

        std::string lineHeader = "", lineBody = "";
        bool secondPart = false;
        for (int i = 0; i < dataLine.length(); i++) {
            if (dataLine[i] == ':') {secondPart = true; continue;}

            if (!secondPart) lineHeader += dataLine[i];
            else lineBody += dataLine[i];
        }
        if (baseAttackConponentsId.find(lineHeader) != baseAttackConponentsId.end()) dataItem[baseAttackConponentsId.at(lineHeader)] = lineBody;
    }

    file.close();
    std::cout << "\tWszystkie: " << all << " Udane: " << good << " Nie udane: " << failed << "\n";
}

void Attacks::addAttackMelee(std::string data[20]) {
    // 0 - name, 1 - lore, 13 - costs {special}
    std::string stringData[3] = {data[0], data[1], data[13]};

    // 0 - lvl, 1 - min_lvl, 2 - rarity
    int intData[3]      = {std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4])}, costs[20];

    // 0 - meleeDamage, 1 - distanceDamage, 2 - meleeDef, 3 - distanceDef, 4 - speed, 5 - range, 6 - chanceOfWork
    float floatData[7]  = {std::stof(data[5]), std::stof(data[6]), std::stof(data[7]), std::stof(data[8]), std::stof(data[9]), std::stof(data[10]), std::stof(data[11])};

    if (stringData[13] != "" && stringData[13] != " ") {
        std::string costData = "";
        int costIndex = 0;
        for (int i = 0; i < stringData[13].length(); i++) {
            if (stringData[13][i] == ',') {
                costs[costIndex] = std::stoi(costData);
                costIndex += 1;
                costData = "";
            }
            costData += stringData[13][i];
        }
    }
    AttacksData.MeleeAttacksArray[AttacksData.MeleeAttacksIndeks] = MeleeAttack (
        stringData[0], stringData[1], intData[0], intData[1], intData[2],
        floatData[0], floatData[1], floatData[2], floatData[3], floatData[4], floatData[5],
        floatData[6], costs
    );
    AttacksData.MeleeAttacksIndeks += 1;
}

void Attacks::loadAttacksRange() {
    int all = 0, good = 0, failed = 0;
    std::string dataLine = "", dataItem[20];
    std::cout << "\n\nLadowanie atakow dystansowych\n";

    std::fstream file;
    file.open("data/attacksRange.txt", std::ios::in);

    while (getline(file, dataLine)) {
        if (dataLine[0] == '-') all += 1;
    }

    file.clear();
    file.seekg(0);

    AttacksData.RangeAttacksArray = new RangeAttack [all];

    while (getline(file, dataLine)) {
        if (dataLine == "" || dataLine[0] == ' ') continue;
        if (dataLine[0] == '-') {
            addAttackRange(dataItem);
            for (int i = 0; i < 20; i++) dataItem[i] = "";
        }

        std::string lineHeader = "", lineBody = "";
        bool secondPart = false;
        for (int i = 0; i < dataLine.length(); i++) {
            if (dataLine[i] == ':') {secondPart = true; continue;}

            if (!secondPart) lineHeader += dataLine[i];
            else lineBody += dataLine[i];
        }
        if (baseAttackConponentsId.find(lineHeader) != baseAttackConponentsId.end()) dataItem[baseAttackConponentsId.at(lineHeader)] = lineBody;
    }

    file.close();

    std::cout << "\tWszystkie: " << all << " Udane: " << good << " Nie udane: " << failed << "\n";
}

void Attacks::addAttackRange(std::string data[20]) {
    // 0 - name, 1 - lore, 13 - costs {special}
    std::string stringData[3] = {data[0], data[1], data[13]};

    // 0 - lvl, 1 - min_lvl, 2 - rarity
    int intData[3]      = {std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4])}, costs[20];

    // 0 - meleeDamage, 1 - distanceDamage, 2 - meleeDef, 3 - distanceDef, 4 - speed, 5 - range, 6 - chanceOfWork
    float floatData[7]  = {std::stof(data[5]), std::stof(data[6]), std::stof(data[7]), std::stof(data[8]), std::stof(data[9]), std::stof(data[10]), std::stof(data[11])};

    if (stringData[13] != "" && stringData[13] != " ") {
        std::string costData = "";
        int costIndex = 0;
        for (int i = 0; i < stringData[13].length(); i++) {
            if (stringData[13][i] == ',') {
                costs[costIndex] = std::stoi(costData);
                costIndex += 1;
                costData = "";
            }
            costData += stringData[13][i];
        }
    }
    AttacksData.RangeAttacksArray[AttacksData.RangeAttacksIndeks] = RangeAttack (
        stringData[0], stringData[1], intData[0], intData[1], intData[2],
        floatData[0], floatData[1], floatData[2], floatData[3], floatData[4], floatData[5],
        floatData[6], costs
    );
    AttacksData.RangeAttacksIndeks += 1;
}

Attacks::MeleeAttack::MeleeAttack (
                std::string name,
                std::string lore,
                int lvl,
                int min_lvl,
                int rarity,
                float meleeDamage,
                float distanceDamage,
                float meleeDef,
                float distanceDef,
                float speed,
                float range,
                float chanceOfWork,
                int *costs
            ) {
    this->name = name;
    this->lore = lore;
    this->lvl  = lvl;
    this->min_lvl = min_lvl;
    this->rarity = rarity;
    this->meleeDamage = meleeDamage;
    this->distanceDamage = distanceDamage,
    this->meleeDef = meleeDef;
    this->distanceDef = distanceDef;
    this->speed = speed;
    this->range = range;
    this->chanceOfWork = chanceOfWork;
    this->costs = costs;
}
Attacks::RangeAttack::RangeAttack (
                std::string name,
                std::string lore,
                int lvl,
                int min_lvl,
                int rarity,
                float meleeDamage,
                float distanceDamage,
                float meleeDef,
                float distanceDef,
                float speed,
                float range,
                float chanceOfWork,
                int *costs
            ) {
    this->name = name;
    this->lore = lore;
    this->lvl  = lvl;
    this->min_lvl = min_lvl;
    this->rarity = rarity;
    this->meleeDamage = meleeDamage;
    this->distanceDamage = distanceDamage,
    this->meleeDef = meleeDef;
    this->distanceDef = distanceDef;
    this->speed = speed;
    this->range = range;
    this->chanceOfWork = chanceOfWork;
    this->costs = costs;
}

