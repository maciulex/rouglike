#include "../../../headers/utilitis/items.hpp"

#include <iostream>

extern int indexMeleeWeapons;
extern gameItems::MeleeWeapon *MeleeWeaponArray;

gameItems::MeleeWeapon::MeleeWeapon(int id, float damage, float speed, float range, float requiredStrenght, int rarity, std::string name, std::string classification, int classficationInt, bool useable) {
    this->id = id;
    this->damage = damage;
    this->speed = speed;
    this->range = range;
    this->classficationInt = classficationInt;
    this->requiredStrenght = requiredStrenght;
    this->rarity = rarity;
    this->name = name;
    this->classification = classification;
    this->useable = useable;
}

void gameItems::drawMoreDataAboutMelee(int index) {
    std::cout << "\n*\t" << "-----------------------------" << std::endl;
    std::cout << "*\t\t" << "Nazwa: " << MeleeWeaponArray[index].name << std::endl;
    std::cout << "*\t\t" << "Rzadkosc: " << MeleeWeaponArray[index].classification << std::endl;
    std::cout << "*\t\t" << "Obrazenia: " << MeleeWeaponArray[index].damage << std::endl;
    std::cout << "*\t\t" << "Szybkosc: " << MeleeWeaponArray[index].speed << std::endl;
    std::cout << "*\t\t" << "Zasieg: " << MeleeWeaponArray[index].range << std::endl;
    std::cout << "*\t\t" << "Wymagana sila: " << MeleeWeaponArray[index].requiredStrenght << std::endl;
    std::cout << "*\t"   << "-----------------------------" << std::endl;
}

void gameItems::drawMelee() {
    std::cout << "Bronie do walki wrecz \"melee\"" << std::endl;
    for (int i = 0; i < indexMeleeWeapons; i++) {
        std::cout << i+1 << ") " << MeleeWeaponArray[i].name << std::endl;
    }
}

std::string gameItems::getMeleeData(int id, std::string what) {
    if (id < 0 || id >= indexMeleeWeapons) {
        return "-1";
    }
    switch (std::hash<std::string>{}(what)) {
        case 14258576900392064537:
            //id
            return std::to_string(MeleeWeaponArray[id].id);
        case 2998709681581561703:
            //damage
            return std::to_string(MeleeWeaponArray[id].damage);
        case 4878149271039768326:
            //speed
            return std::to_string(MeleeWeaponArray[id].speed);
        case 2914616072447184159:
            //range
            return std::to_string(MeleeWeaponArray[id].range);
        case 11812193097163427324:
            //classficationInt
            return std::to_string(MeleeWeaponArray[id].classficationInt);
        case 17918958457440324476:
            //requiredStrenght
            return std::to_string(MeleeWeaponArray[id].requiredStrenght);
        case 13862207918752884272:
            //rarity
            return std::to_string(MeleeWeaponArray[id].rarity);
        case 10420554295983197538:
            //name
            return MeleeWeaponArray[id].name;
        case 11728969269359993017:
            //classification
            return MeleeWeaponArray[id].classification;
        case 11430414146544851443:
            //useable
            return ((MeleeWeaponArray[id].useable) ? "1" : "0");
    }
    return "-1";
}
