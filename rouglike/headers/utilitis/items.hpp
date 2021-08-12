
#ifndef __ITEMS_HPP
#define __ITEMS_HPP
#include <string>
    namespace gameItems {
        extern int maxWeapons;
        extern int maxMeleeWeapons;
        extern int maxRangeWeapons;
        extern int indexMeleeWeapons;
        extern int indexRangeWeapons;

        void addWeapon();
        void loadWeapons();
        void deafaultItemsLoad();
        void drawItems(int whichType);

        class Weapon {
            public:
                int id, classficationInt;
                float damage, speed, range,requiredStrenght,requiredInt;
                std::string name, classification;
        };

        class MeleeWeapon : public Weapon {
            public:
                MeleeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, int classficationInt = 0, float requiredStrenght = 0, std::string name = "no name", std::string classification = "no classification");
        };

        class RangeWeapon : public Weapon {
            public:
                RangeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, int classficationInt = 0, float requiredStrenght = 0, std::string name = "no name", std::string classification = "no classification");
        };
    };
#endif
