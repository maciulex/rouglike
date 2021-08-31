#ifndef __MONSTERS.HPP
#define __MONSTERS.HPP
#include <string>

namespace Monsters {
    class Monsters;

    struct MonsterDataStruct {
        int MonstersArrayIndex = 0, MonstersArrayMax = 0;
        Monsters *MonstersArray;


    };

    //extern MonsterDataStruct MonstersData;

    void loadMonsters();
    void addMonster(std::string data[20]);

    class Monsters {
        public:
            std::string name, lore, graphic;
            int id, lvl, min_lvl, max_lvl, showUpRange;
            float hp, mana, strenght, speed, range, baseDef, distanceDef, meleeDef;
            bool rangeFighter, meleeFighter;

            Monsters(
                int id = 0,
                std::string name = "???",
                std::string lore = "No lore",
                std::string graphic = "D:",
                int lvl = 1,
                int min_lvl = 0,
                int max_lvl = 999,
                int showUpRange = 10,
                float hp = 1,
                float mana = 1,
                float strenght = 1,
                float speed = 1,
                float range = 1,
                float baseDef = 1,
                float distanceDef = 1,
                float meleeDef = 1,
                bool meleeFighter = true,
                bool rangeFighter = false
            );
            void drawMonster();
            std::string getMonsterName(int length = -1, bool overwrite = true);
            std::string getMonsterLevel(int length = -1, bool overwrite = true);
            std::string getMonsterShowUpRange(int length = -1, bool overwrite = true);
    };
}
#endif
