#include "../../../headers/utilitis/items.hpp"

#include <iostream>

extern int indexHealWeapons;
extern gameItems::HealPotion *HealPotionArray;

gameItems::HealPotion::HealPotion(int id, std::string effect, int rarity, std::string name, std::string lore, std::string classification, int classficationInt, std::string optional_effect, bool useable) {
    this->id = id;
    this->effect = effect;
    this->rarity = rarity;
    this->name = name;
    this->lore = lore;
    this->classification = classification;
    this->classficationInt = classficationInt;
    this->optional_effect = optional_effect;
    this->useable = useable;
}
void gameItems::drawHeal() {
    std::cout << "Potiony leczenia \"heal\"" << std::endl;
    std::cout << indexHealWeapons << std::endl;
    std::cout << HealPotionArray[0].name << std::endl;
    for (int i = 0; i < indexHealWeapons; i++) {
        std::cout << i+1 << ") " << HealPotionArray[i].name << std::endl;
    }
}

void gameItems::drawMoreDataAboutHeal(int index) {
    std::cout << "\n*\t" << "-----------------------------" << std::endl;
    std::cout << "*\t\t" << "Nazwa: " << HealPotionArray[index].name << std::endl;
    std::cout << "*\t\t" << "Rzadkosc: " << HealPotionArray[index].classification << std::endl;
    std::cout << "*\t\t" << "Opis: " << HealPotionArray[index].lore << std::endl;
    std::cout << "*\t"   << "-----------------------------" << std::endl;
}

std::string gameItems::getHealData(int id, std::string what) {
    if (id < 0 || id >= indexHealWeapons) {
        return "-1";
    }
    switch (std::hash<std::string>{}(what)) {
        case 14258576900392064537:
            //id
            return std::to_string(HealPotionArray[id].id);
        case 12580124215795132112:
            //lore
            return HealPotionArray[id].lore;
        case 11474446143787603490:
            //effect
            return HealPotionArray[id].effect;
        case 9080392314480909697:
            //optional_effect
            return HealPotionArray[id].optional_effect;
        case 11812193097163427324:
            //classficationInt
            return std::to_string(HealPotionArray[id].classficationInt);
        case 13862207918752884272:
            //rarity
            return std::to_string(HealPotionArray[id].rarity);
        case 10420554295983197538:
            //name
            return HealPotionArray[id].name;
        case 11728969269359993017:
            //classification
            return HealPotionArray[id].classification;
        case 11430414146544851443:
            //useable
            return ((HealPotionArray[id].useable) ? "1" : "0");
    }
    return "-1";
}
