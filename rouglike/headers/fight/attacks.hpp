#ifndef __ATTACKS.HPP
#define __ATTACKS.HPP
#include <string>

namespace Attacks {
    class Attack;
    class MeleeAttack;
    class RangeAttack;

    struct AttacksDataStruct {
        int MeleeAttacksIndeks = 0, MeleeAttacksMax, RangeAttacksIndeks = 0, RangeAttacksMax;

        MeleeAttack *MeleeAttacksArray;
        RangeAttack *RangeAttacksArray;

    };

    void loadAttacks();

    void loadAttacksMelee();
    void addAttackMelee(std::string data[20]);

    void loadAttacksRange();
    void addAttackRange(std::string data[20]);

    std::string getAttackData(int which = -1, int index = -1, std::string what = "-1");

    class Attack {
        protected:
            std::string name, lore;
            int lvl, min_lvl, rarity, *costs;
            float meleeDamage, distanceDamage, meleeDef, distanceDef, speed, range, chanceOfWork, meleeWeaponBust, rangeWeaponBoost;
            bool meleeWeaponRequired, rangeWeaponRequired;
        public:
            std::string getAttackName(int length = -1, bool overwrite = true);
            std::string getAttackLevel(int length = -1, bool overwrite = true);
            std::string getAttackRange(int length = -1, bool overwrite = true);
            std::string getAttackBaseData(std::string which);
    };
    class MeleeAttack : public Attack {
        public:
            MeleeAttack(
                std::string name = "noName",
                std::string lore = "noLore",
                int lvl = 1,
                int min_lvl = 1,
                int rarity = 1,
                float meleeDamage = 1,
                float distanceDamage = 1,
                float meleeDef = 1,
                float distanceDef = 1,
                float speed = 1,
                float range = 1,
                float chanceOfWork = 1,
                int *costs = new int [1],
                bool meleeWeaponRequired = false,
                float meleeWeaponBust = 0,
                bool rangeWeaponRequired = false,
                float rangeWeaponBoost = 0
            );
    };
    class RangeAttack : public Attack {
        public:
            RangeAttack (
                std::string name = "noName",
                std::string lore = "noLore",
                int lvl = 1,
                int min_lvl = 1,
                int rarity = 1,
                float meleeDamage = 1,
                float distanceDamage = 1,
                float meleeDef = 1,
                float distanceDef = 1,
                float speed = 1,
                float range = 1,
                float chanceOfWork = 1,
                int *costs = new int [1],
                bool meleeWeaponRequired = false,
                float meleeWeaponBust = 0,
                bool rangeWeaponRequired = false,
                float rangeWeaponBoost = 0
            );
    };
}
#endif
