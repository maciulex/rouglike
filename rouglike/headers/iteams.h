#ifndef __ITEMS_H
#define __ITEMS_H
#include <string>

    namespace gameItems {
        class Weapon {
            public:
                int id, classficationInt;
                float damage, speed, range, requiredStrenght;
                std::string name, classification;
        };
        class MeleeWeapon : public Weapon {
            public:
                MeleeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, int classficationInt = 0, float requiredStrenght = 0, std::string name = "no name", std::string classification = "no classification");
        };
        void loadWeapons();
        void loadMeleeWeapons();
    };
#endif
