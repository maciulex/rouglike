#ifndef __ITEMS_H
#define __ITEMS_H
#include <string>
    namespace gameItems {
        class Weapon {
            public:
                int id, damage, speed, range, classficationInt, requiredStrenght;
                string name, classification;
        };
        class MeleeWeapon : public Weapon {

        };

    };
#endif
