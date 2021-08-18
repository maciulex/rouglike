#include "../../../headers/utilitis/items.hpp"

#include <iostream>

extern int indexRangeWeapons;
extern gameItems::RangeWeapon *RangeWeaponArray;

gameItems::RangeWeapon::RangeWeapon(int id, float damage, float speed, float range, int classficationInt, float requiredInt, int rarity, std::string name, std::string classification) {
    this->id = id;
    this->damage = damage;
    this->speed = speed;
    this->range = range;
    this->classficationInt = classficationInt;
    this->requiredInt = requiredInt;
    this->rarity = rarity;
    this->name = name;
    this->classification = classification;
}

void gameItems::drawRange() {
    std::cout << "Bronie do walki na odlegoosc \"range\"" << std::endl;
    for (int i = 0; i < indexRangeWeapons; i++) {
        std::cout << i+1 << ") " << RangeWeaponArray[i].name << std::endl;
    }
}

std::string gameItems::getRangeData(int id, std::string what) {
    if (id < 0 || id >= indexRangeWeapons) {
        return "-1";
    }
    switch (std::hash<std::string>{}(what)) {
        case 14258576900392064537:
            //id
            return std::to_string(RangeWeaponArray[id].id);
        case 2998709681581561703:
            //damage
            return std::to_string(RangeWeaponArray[id].damage);
        case 4878149271039768326:
            //speed
            return std::to_string(RangeWeaponArray[id].speed);
        case 2914616072447184159:
            //range
            return std::to_string(RangeWeaponArray[id].range);
        case 11812193097163427324:
            //classficationInt
            return std::to_string(RangeWeaponArray[id].classficationInt);
        case 13302216649247095329:
            //requiredInt
            return std::to_string(RangeWeaponArray[id].requiredStrenght);
        case 13862207918752884272:
            //rarity
            return std::to_string(RangeWeaponArray[id].rarity);
        case 10420554295983197538:
            //name
            return RangeWeaponArray[id].name;
        case 11728969269359993017:
            //classification
            return RangeWeaponArray[id].classification;
    }
    return "-1";
}
