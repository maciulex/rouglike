
#ifndef __ITEMS_HPP
#define __ITEMS_HPP
#include <string>
    namespace gameItems {
        class Weapon;
        class MeleeWeapon;
        class RangeWeapon;

        extern int maxWeapons;
//        extern int indexMeleeWeapons;
//        extern int indexRangeWeapons;
//        extern MeleeWeapon *MeleeWeaponArray;
//        extern RangeWeapon *RangeWeaponArray;


        void addWeapon(std::string data[10]);
        void addOther(std::string data[8]);
        void loadIteams();
        void loadWeapons();
        void loadOther();
        void deafaultItemsLoad();
        void drawItems(int whichType);
        void drawRange();
        void drawMelee();
        void drawHeal();
        void drawBuff();
        std::string getWeaponData(int type, int id, std::string what);
        // type [0] melee [1] range
        std::string getMeleeData(int id, std::string what);
        std::string getRangeData(int id, std::string what);

        class Weapon {
            public:
                int id, classficationInt, rarity;
                float damage, speed, range,requiredStrenght, requiredInt;
                std::string name, classification;
        };
        class otherIteams {
            public:
                int id, classficationInt, rarity;
                std::string name, lore, classification;
        };
        class HealPotion : public otherIteams {
            std::string effect, optional_effect;
            public:
                HealPotion(int id = 0, std::string effect = "", int rarity = 1, std::string name = "no name", std::string lore = "no lore", std::string classification = "no classification", int classficationInt = 3, std::string optional_effect = "");
        };
        class BuffPotion : public otherIteams {
            std::string buff, optional_effect;
            public:
                BuffPotion(int id = 0, std::string buff = "", int rarity = 1, std::string name = "no name", std::string lore = "no lore", std::string classification = "no classification", int classficationInt = 4, std::string optional_effect = "");
        };
        class MeleeWeapon : public Weapon {
            public:
                MeleeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, float requiredStrenght = 0, int rarity = 1, std::string name = "no name", std::string classification = "no classification", int classficationInt = 1);
        };

        class RangeWeapon : public Weapon {
            public:
                RangeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, float requiredStrenght = 0, int rarity = 1, std::string name = "no name", std::string classification = "no classification", int classficationInt = 2);
        };
    };
#endif
