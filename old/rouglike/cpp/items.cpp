#include "../headers/iteams.h"
#include <string>

gameItems::MeleeWeapon MeleeWeaponArrray[1];

void gameItems::loadWeapons() {
    loadMeleeWeapons();
}
void gameItems::loadMeleeWeapons() {
    MeleeWeaponArrray[0] = MeleeWeapon(1,1,1,1,1,1,"blade","bardzo pospolite");
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
