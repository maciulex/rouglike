#include "../../../headers/utilitis/items.hpp"

#include <iostream>
#include <array>

extern int indexBuffWeapons;
extern gameItems::BuffPotion *BuffPotionArray;

gameItems::BuffPotion::BuffPotion(int id, std::string buff, int rarity, std::string name, std::string lore, std::string classification, int classficationInt, std::string optional_effect) {
    this->id = id;
    this->buff = buff;
    this->rarity = rarity;
    this->name = name;
    this->lore = lore;
    this->classification = classification;
    this->classficationInt = classficationInt;
    this->optional_effect = optional_effect;
}

void gameItems::drawBuff() {
    std::cout << "Potiony ulepszen \"buff\"" << std::endl;
    for (int i = 0; i < indexBuffWeapons; i++) {
        std::cout << i+1 << ") " << BuffPotionArray[i].name << std::endl;
    }
}
