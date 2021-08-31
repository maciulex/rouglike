#include "../../headers/fight/monsters.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

Monsters::MonsterDataStruct MonstersData;


void Monsters::loadMonsters() {
    std::string fileLine;
    std::fstream file;
    file.open("data/monsters.txt", std::ios::in);
    if (!file.good()) {
        std::cout << "Brak pliku z potworami >:";
        exit(70);
    }
    while (std::getline(file, fileLine)) {
        if (fileLine[0] == '-') {
            MonstersData.MonstersArrayMax += 1;
        }
    }
    file.clear();
    file.seekg(0);

    MonstersData.MonstersArray = new Monsters [MonstersData.MonstersArrayMax];
    std::unordered_map<std::string, int> ValidationData {
            {"id",              0},
            {"name",            1},
            {"lore",            2},
            {"graphic",         3},
            {"lvl",             4},
            {"min_lvl",         5},
            {"max_lvl",         6},
            //end of required
            {"hp",              7},
            {"mana",            8},
            {"strenght",        9},
            {"speed",           10},
            {"range",           11},
            {"baseDef",         12},
            {"distanceDef",     13},
            {"meleeDef",        14},
            {"meleeFighter",    15},
            {"rangeFighter",    16},
            {"showUpRange",     17}
    };
    int requiredIndexMax = 6;
    std::string data[20];
    bool validation[10] = {false}, graphic = false;

    while (std::getline(file, fileLine)) {
        std::string lineData[2] = {""};
        bool secondPart = false;
        if (graphic) {
            //graphic_end
            if (fileLine[0] == 'g' && fileLine[1] == 'r' && fileLine[9] == 'n' && fileLine[10] == 'd') {
                graphic = false;
                validation[3] = true;
                data[3] += "\t----------------------------------------------------------------------------------------------------\n";
                continue;
            }
            data[3] += "\t|" + fileLine + "|" + "\n";
        }
        if (fileLine[0] == '-') {
            bool good = true;
            for (int i = 0; i <= requiredIndexMax; i++) {
                if (!validation[i]) {
                    good = false;
                    break;
                }
            }
            if (good) addMonster(data);
            for (int i = 0; i < 20; i++) {
                data[i] = "";
            }
        }
        for (int i = 0; i < fileLine.length(); i++) {
            if (fileLine[i] == ':') {
                secondPart = true;
                continue;
            }
            if (!secondPart) lineData[0] += fileLine[i];
            else lineData[1] += fileLine[i];
        }
        if (ValidationData.find(lineData[0]) != ValidationData.end()) {
            int index = ValidationData.at(lineData[0]);
            if (index == 3) {
                graphic = true;
                data[3] += "\t----------------------------------------------------------------------------------------------------\n";
                continue;
            }
            data[index] = lineData[1];
            if (index <= requiredIndexMax) validation[index] = true;
        }
    }

    file.close();
}
void Monsters::addMonster(std::string data[20]) {
    try {
        int id, lvl, min_lvl, max_lvl, showUpRange;
        float dataFloated[15] = {1};
        std::string name, lore, graphic;
        bool meleeFighter, rangeFighter;
        for (int i = 0; i < 20; i++) {
            switch (i) {
                case 0:
                    if (data[i] == "") continue;
                    id = std::stoi(data[i]);
                break;
                case 1:
                    if (data[i] == "") continue;
                    name = data[i];
                break;
                case 2:
                    if (data[i] == "") continue;
                    lore = data[i];
                break;
                case 3:
                    if (data[i] == "") continue;
                    graphic = data[i];
                break;
                case 4:
                    if (data[i] == "") continue;
                    lvl = std::stoi(data[i]);
                break;
                case 5:
                    if (data[i] == "") continue;
                    min_lvl = std::stoi(data[i]);
                break;
                case 6:
                    if (data[i] == "") continue;
                    max_lvl = std::stoi(data[i]);
                break;
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                    if (data[i] == "") continue;
                    dataFloated[i] = std::stof(data[i]);
                break;
                case 15:
                    if (data[i] == "") continue;
                    meleeFighter = ((data[i] == "1") ? true : false);
                break;
                case 16:
                    if (data[i] == "") continue;
                    rangeFighter = ((data[i] == "1") ? true : false);
                break;
                case 17:
                    if (data[i] == "") continue;
                    showUpRange = std::stoi(data[i]);
                break;
            }
        }
        for (int i = 7; i <= 14; i++) {
            if (data[i] != "") {
                dataFloated[i] = std::stof(data[i]);
            }
        }
        MonstersData.MonstersArray[MonstersData.MonstersArrayIndex] = Monsters(
        id, name, lore, graphic, lvl, min_lvl, max_lvl, showUpRange, dataFloated[7], dataFloated[8], dataFloated[9], dataFloated[10],
        dataFloated[11], dataFloated[12], dataFloated[13], dataFloated[14], meleeFighter, rangeFighter);
        MonstersData.MonstersArrayIndex += 1;
    } catch (std::exception &e) {
        std::cout << "error podczas ladowania broni" << std::endl;
        return;
    }
}

void Monsters::Monsters::drawMonster() {
    std::cout << graphic << std::endl;
}

std::string Monsters::Monsters::getMonsterName(int endLength, bool overwrite) {
    if (endLength == -1) return name;
    if (endLength < name.length()) {
        if (overwrite) return name.substr(0, endLength);
        return name;
    }
    return name + std::string(endLength-name.length(), 32);
}

std::string Monsters::Monsters::getMonsterLevel(int endLength, bool overwrite) {
    std::string levelString = std::to_string(lvl);
    if (endLength == -1) return levelString;
    if (endLength < levelString.length()) {
        if (overwrite) return levelString.substr(0, endLength);
        return levelString;
    }
    return levelString + std::string(endLength-levelString.length(), 32);
}

std::string Monsters::Monsters::getMonsterShowUpRange(int endLength, bool overwrite) {
    std::string showUpRangeString = std::to_string(showUpRange);
    if (endLength == -1) return showUpRangeString;
    if (endLength < showUpRangeString.length()) {
        if (overwrite) return showUpRangeString.substr(0, endLength);
        return showUpRangeString;
    }
    return showUpRangeString + std::string(endLength-showUpRangeString.length(), 32);
}

Monsters::Monsters::Monsters(
    int id,
    std::string name,
    std::string lore,
    std::string graphic,
    int lvl,
    int min_lvl,
    int max_lvl,
    int showUpRange,
    float hp,
    float mana,
    float strenght,
    float speed,
    float range,
    float baseDef,
    float distanceDef,
    float meleeDef,
    bool meleeFighter,
    bool rangeFighter
) {
    this->id = id;
    this->name = name;
    this->graphic = graphic;
    this->lvl = lvl;
    this->min_lvl = min_lvl;
    this->max_lvl = max_lvl;
    this->showUpRange = showUpRange;
    this->hp = hp;
    this->mana = mana;
    this->strenght = strenght;
    this->speed = speed;
    this->range = range;
    this->baseDef = baseDef;
    this->distanceDef = distanceDef;
    this->meleeDef = meleeDef;
    this->meleeFighter = meleeFighter;
    this->rangeFighter = rangeFighter;

};
