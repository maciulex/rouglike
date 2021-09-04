
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
        void drawItems(int whichType);
        std::string getItemData(int type, int id, std::string what);
        // type [0] melee [1] range, [2] heal 3[range]


        //melee.cpp
        void drawMelee();
        void drawMoreDataAboutMelee(int index);
        std::string getMeleeData(int id, std::string what);

        //range.cpp
        void drawRange();
        void drawMoreDataAboutRange(int index);
        std::string getRangeData(int id, std::string what);

        //heal.cpp
        void drawHeal();
        void drawMoreDataAboutHeal(int index);
        std::string getHealData(int id, std::string what);

        //buff.cpp
        void drawBuff();
        void drawMoreDataAboutBuff(int index);
        std::string getBuffData(int id, std::string what);

        class Weapon {
            public:
                bool useable;
                int id, classficationInt, rarity;
                float damage, speed, range,requiredStrenght, requiredInt;
                std::string name, classification;
        };
        class otherIteams {
            public:
                bool useable;
                int id, classficationInt, rarity;
                std::string name, lore, classification;
        };
        class HealPotion : public otherIteams {
            public:
                std::string effect, optional_effect;
                HealPotion(int id = 0, std::string effect = "", int rarity = 1, std::string name = "no name", std::string lore = "no lore", std::string classification = "no classification", int classficationInt = 3, std::string optional_effect = "", bool useable = true);
        };
        class BuffPotion : public otherIteams {
            public:
                std::string buff, optional_effect;
                BuffPotion(int id = 0, std::string buff = "", int rarity = 1, std::string name = "no name", std::string lore = "no lore", std::string classification = "no classification", int classficationInt = 4, std::string optional_effect = "", bool useable = true);
        };
        class MeleeWeapon : public Weapon {
            public:
                MeleeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, float requiredStrenght = 0, int rarity = 1, std::string name = "no name", std::string classification = "no classification", int classficationInt = 1, bool useable = true);
        };

        class RangeWeapon : public Weapon {
            public:
                RangeWeapon(int id = 0, float damage = 0, float speed = 0, float range = 0, float requiredStrenght = 0, int rarity = 1, std::string name = "no name", std::string classification = "no classification", int classficationInt = 2, bool useable = true);
        };
    };
#endif
