#include "../../headers/fight/attacks.hpp"

#include <iostream>
#include <fstream>
#include <unordered_map>

Attacks::AttacksDataStruct AttacksData;

std::unordered_map<std::string, int> baseAttackConponentsId = {
    {"name",                0},
    {"lore",                1},
    {"lvl",                 2},
    {"min_lvl",             3},
    {"rarity",              4},
    {"meleeDamage",         5},
    {"distanceDamage",      6},
    {"meleeDef",            7},
    {"distanceDef",         8},
    {"speed",               9},
    {"range",               10},
    {"chanceOfWork",        11},
    {"attackType",          12},
    {"costs",               13},
    {"meleeWeaponRequired", 14},
    {"meleeWeaponBust",     15},
    {"rangeWeaponRequired", 16},
    {"rangeWeaponBoost",    17}
};

void Attacks::loadAttacks() {
    std::cout << std::endl << "Ladowanie atakow";

    loadAttacksMelee();
    loadAttacksRange();

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

    // 0 - meleeWeaponRequired, 1 - rangeWeaponRequired
    bool boolData[2] = {((data[14] == "" || data[14] == "false" || data[14] == "0") ? false : true), ((data[16] == "" || data[16] == "false" || data[16] == "0") ? false : true)};

    // 0 - meleeWeaponBust, 1 - rangeWeaponBoost
    float bustData[2] = {((data[15] == "" || data[15][0] == ' ') ? 0 : std::stof(data[15])), ((data[17] == "" || data[17][0] == ' ') ? 0 : std::stof(data[17]))};

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
        floatData[6], costs, boolData[0], bustData[0], boolData[1], bustData[1]
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

    // 0 - meleeWeaponRequired, 1 - rangeWeaponRequired
    bool boolData[2] = {((data[14] == "" || data[14] == "false" || data[14] == "0") ? false : true), ((data[16] == "" || data[16] == "false" || data[16] == "0") ? false : true)};

    // 0 - meleeWeaponBust, 1 - rangeWeaponBoost
    float bustData[2] = {((data[15] == "" || data[15][0] == ' ') ? 0 : std::stof(data[15])), ((data[17] == "" || data[17][0] == ' ') ? 0 : std::stof(data[17]))};

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
        floatData[6], costs, boolData[0], bustData[0], boolData[1], bustData[1]
    );
    AttacksData.RangeAttacksIndeks += 1;
}

std::string Attacks::Attack::getAttackBaseData(std::string which) {
    std::string dataHolder = "";
    switch (std::hash<std::string>{}(which)) {
        case 10420554295983197538:
//      name
            return name;
        case 12580124215795132112:
//      lore
            return name;
        case 15869450025595216493:
//      lvl
            return std::to_string(lvl);
        case 11412875497007605674:
//      min_lvl
            return std::to_string(min_lvl);
        case 13862207918752884272:
//      rarity
            return std::to_string(rarity);
        case 1738818891027217700:
//      costs
            for (int i = 0; i < sizeof(costs)/sizeof(costs[0]); i++) {
                dataHolder+=std::to_string(costs[i])+";";
            }
            return dataHolder;
        break;
        case 7751017261663934291:
//      meleeDamage
            return std::to_string(meleeDamage);
        case 12906888805078331497:
//      distanceDamage
            return std::to_string(distanceDamage);
        case 13340486775697793372:
//      meleeDef
            return std::to_string(meleeDef);
        case 6144278194197645852:
//      distanceDef
            return std::to_string(distanceDef);
        case 4878149271039768326:
//      speed
            return std::to_string(speed);
        case 2914616072447184159:
//      range
            return std::to_string(range);
        case 7541432946876866494:
//      chanceOfWork
            return std::to_string(chanceOfWork);
        case 10254150431226174848:
//      meleeWeaponBust
            return std::to_string(meleeWeaponBust);
        case 5331270416000234977:
//      rangeWeaponBust
            return std::to_string(rangeWeaponBoost);
        case 5351291873868752646:
//      meleeWeaponRequired
            return std::to_string(meleeWeaponRequired);
        case 1311252456542697337:
//      rangeWeaponRequired
            return std::to_string(rangeWeaponRequired);
    }
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
                int *costs,
                bool meleeWeaponRequired,
                float meleeWeaponBust,
                bool rangeWeaponRequired,
                float rangeWeaponBoost
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
    this->meleeWeaponRequired = meleeWeaponRequired;
    this->meleeWeaponBust = meleeWeaponBust;
    this->rangeWeaponRequired = rangeWeaponRequired;
    this->rangeWeaponBoost = rangeWeaponBoost;
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
                int *costs,
                bool meleeWeaponRequired,
                float meleeWeaponBust,
                bool rangeWeaponRequired,
                float rangeWeaponBoost
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
    this->meleeWeaponRequired = meleeWeaponRequired;
    this->meleeWeaponBust = meleeWeaponBust;
    this->rangeWeaponRequired = rangeWeaponRequired;
    this->rangeWeaponBoost = rangeWeaponBoost;
}

