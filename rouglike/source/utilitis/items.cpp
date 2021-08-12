#include "../../headers/utilitis/items.hpp"
#include <string>
#include <fstream>
#include <iostream>

int maxWeapons = 1;
int maxMeleeWeapons;
int maxRangeWeapons;
int indexMeleeWeapons = 0;
int indexRangeWeapons = 0;

gameItems::MeleeWeapon MeleeWeaponArray[1];
gameItems::RangeWeapon RangeWeaponArray[1];

void gameItems::loadWeapons() {
    std::fstream file;
    file.open("weapons.txt", std::ios::in);
    if (!file.good()) {
       std::cout << "\n\nBrak pliku z bronmi!" << std::endl;
       system("pause");
       exit(69);
    }
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

}
void gameItems::addWeapon() {

}

void gameItems::drawItems(int whichType) {
//    if (whichType == 1) {
//        for (int i = 0; i < indexMeleeWeapons; i++) {
//
//        }
//    } else {
//        for (int i = 0; i < indexRangeWeapons; i++) {
//
//        }
//    }
}

gameItems::MeleeWeapon::MeleeWeapon(int id, float damage, float speed, float range, int classficationInt, float requiredStrenght, std::string name, std::string classification) {
    this->id = id;
    this->damage = damage;
    this->speed = speed;
    this->range = range;
    this->classficationInt = classficationInt;
    this->requiredStrenght = requiredStrenght;
    this->name = name;
    this->classification = classification;
}
gameItems::RangeWeapon::RangeWeapon(int id, float damage, float speed, float range, int classficationInt, float requiredInt, std::string name, std::string classification) {
    this->id = id;
    this->damage = damage;
    this->speed = speed;
    this->range = range;
    this->classficationInt = classficationInt;
    this->requiredInt = requiredInt;
    this->name = name;
    this->classification = classification;
}
