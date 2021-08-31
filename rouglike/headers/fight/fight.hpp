#ifndef __FIGHT_HPP
#define __FIGHT_HPP

#include "monsters.hpp"

    namespace Fight {
        struct {
            //actuallFight
            int combination[32] = {0}, amountOfCombintaions = 1, combinationIndeks;

            //other
            float difficultyModifier, endDifficulty;
            int enemiesNumber, actuallAttacker;
            bool playerTour, fightStart = false;

            Monsters::Monsters monsters[3];

        } FightData;


        void prepareFight(float localDifficultyModifier = 0);
        void endBattle();
        void engineFight();
        void generateFightCombination();
        void nextMonster();
        void killMonster(int indeks);
        void addFightDirectory(int directory = 0);
        void prepareMonsters();
        int getMonsterID(float lvl);
        std::string getSpecialMessageFight(int which = 0, int lenght = -1, bool overwrite = true);
        void drawMonsterAddictionalData();
        void drawActuallMonster();
        void drawMonsterHp();
        void fight();

    }
#endif
