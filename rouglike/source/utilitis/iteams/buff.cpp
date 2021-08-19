#include "../../../headers/utilitis/items.hpp"

#include <iostream>
#include <array>

extern int indexBuffWeapons;
extern gameItems::BuffPotion *BuffPotionArray;

gameItems::BuffPotion::BuffPotion(int id, std::string buff, int rarity, std::string name, std::string lore, std::string classification, int classficationInt, std::string optional_effect, bool useable) {
    this->id = id;
    this->buff = buff;
    this->rarity = rarity;
    this->name = name;
    this->lore = lore;
    this->classification = classification;
    this->classficationInt = classficationInt;
    this->optional_effect = optional_effect;
    this->useable = useable;
}

void gameItems::drawBuff() {
    std::cout << "Potiony ulepszen \"buff\"" << std::endl;
    for (int i = 0; i < indexBuffWeapons; i++) {
        std::cout << i+1 << ") " << BuffPotionArray[i].name << std::endl;
    }
}

void gameItems::drawMoreDataAboutBuff(int index) {
    std::cout << "\n*\t" << "-----------------------------" << std::endl;
    std::cout << "*\t\t" << "Nazwa: " << BuffPotionArray[index].name << std::endl;
    std::cout << "*\t\t" << "Rzadkosc: " << BuffPotionArray[index].classification << std::endl;
    std::cout << "*\t\t" << "Opis: " << BuffPotionArray[index].lore << std::endl;
    std::cout << "*\t"   << "-----------------------------" << std::endl;
}

std::string gameItems::getBuffData(int id, std::string what) {
    if (id < 0 || id >= indexBuffWeapons) {
        return "-1";
    }
    switch (std::hash<std::string>{}(what)) {
        case 14258576900392064537:
            //id
            return std::to_string(BuffPotionArray[id].id);
        case 12580124215795132112:
            //lore
            return BuffPotionArray[id].lore;
        case 11474446143787603490:
        case 13576328558316791519:
            //effect/buff
            return BuffPotionArray[id].buff;
        case 9080392314480909697:
            //optional_effect
            return BuffPotionArray[id].optional_effect;
        case 11812193097163427324:
            //classficationInt
            return std::to_string(BuffPotionArray[id].classficationInt);
        case 13862207918752884272:
            //rarity
            return std::to_string(BuffPotionArray[id].rarity);
        case 10420554295983197538:
            //name
            return BuffPotionArray[id].name;
        case 11728969269359993017:
            //classification
            return BuffPotionArray[id].classification;
        case 11430414146544851443:
            //useable
            return ((BuffPotionArray[id].useable) ? "1" : "0");
    }
    return "-1";
}
