#ifndef __FIGHT_HPP
#define __FIGHT_HPP

#include "monsters.hpp"

    namespace Fight {
        struct {
            float difficultyModifier, endDifficulty;
            int enemiesNumber, actuallAttacker;
            bool playerTour;


            Monsters::Monsters monsters[3];

        } FightData;


        void prepareFight(float localDifficultyModifier = 0);
        void prepareMonsters();
        int getMonsterID(float lvl);
        std::string getSpecialMessageFight(int which = 0, int lenght = -1, bool overwrite = true);
        void drawMonsterAddictionalData();
        void drawActuallMonster();
        void fight();

    }
#endif
