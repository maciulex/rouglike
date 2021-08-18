#include "../../../headers/utilitis/items.hpp"

#include <iostream>

extern int indexHealWeapons;
extern gameItems::HealPotion *HealPotionArray;

gameItems::HealPotion::HealPotion(int id, std::string effect, int rarity, std::string name, std::string, std::string classification, int classficationInt, std::string optional_effect) {
    this->id = id;
    this->effect = effect;
    this->rarity = rarity;
    this->name = name;
    this->lore = lore;
    this->classification = classification;
    this->classficationInt = classficationInt;
    this->optional_effect = optional_effect;
}
void gameItems::drawHeal() {
    std::cout << "Potiony leczenia \"heal\"" << std::endl;
    std::cout << indexHealWeapons << std::endl;
    std::cout << HealPotionArray[0].name << std::endl;
    for (int i = 0; i < indexHealWeapons; i++) {
        std::cout << i+1 << ") " << HealPotionArray[i].name << std::endl;
    }
}
