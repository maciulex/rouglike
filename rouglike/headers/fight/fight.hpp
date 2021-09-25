#ifndef __FIGHT_HPP
#define __FIGHT_HPP

#include "monsters.hpp"

    namespace Fight {
        struct FightDataStruct {
            //actuallFight
            int combination[32], acutalInputCombination[32], amountOfCombintaions = 1, combinationIndeks = 0, attack[2], timeForOne;
            bool fastEndEnter;

            //other
            float difficultyModifier, endDifficulty;
            int enemiesNumber, actuallAttacker;
            bool playerTour, fightStart = false;

            Monsters::Monsters monsters[3];

        };


        void prepareFight(float localDifficultyModifier = 0);
        void endBattle();
        void engineFight();
        void battleGo();
        void generateFightCombination();
        void generateTimeCombination();
        void generateResult();
        void drawFightResult(float dmgGiven = 0, float dmgRecived = 0);
        void fightResult(double goodPercent);
        void nextMonster();
        void killMonster(int indeks);
        void addFightDirectory(int directory = 0);
        void prepareMonsters();
        int getMonsterID(float lvl);
        std::string getSpecialMessageFight(int which = 0, int lenght = -1, bool overwrite = true);
        void drawMonsterAddictionalData();
        void drawActuallMonster();
        void getAttack(int attackType);
        void drawMonsterHp();
        void fight();

    }
#endif
