#include "../../headers/fight/fight.hpp"

#include "../../headers/game.hpp"
#include "../../headers/global.hpp"
#include "../../lib/color3.hpp"
#include "../../headers/fight/monsters.hpp"

#include <iostream>

extern Monsters::MonsterDataStruct MonstersData;

void Fight::prepareFight(float localDifficultyModifier) {
    FightData.difficultyModifier = localDifficultyModifier;
    FightData.endDifficulty = Game::getDifficulty()*localDifficultyModifier+GameVariables.level;
    FightData.enemiesNumber = rand()%3+1;
    FightData.actuallAttacker = 0;

    prepareMonsters();

    GameVariables.battle = true;
    GameVariables.hud = 3;
    Game::setSpecialMessages("Walka sie rozpoczela!", 0);
    Game::setSpecialMessages((std::to_string(FightData.enemiesNumber)+": pojawilo sie przeciwnikow!"), 1);
}

void Fight::prepareMonsters() {
    for (int i = 0; i < FightData.enemiesNumber; i++) {
        Monsters::Monsters localMonster;
        localMonster = MonstersData.MonstersArray[getMonsterID(FightData.endDifficulty)];

        localMonster.showUpRange = rand()%localMonster.showUpRange+1;

        FightData.monsters[i] = localMonster;
    }
}

void Fight::drawActuallMonster() {
    FightData.monsters[FightData.actuallAttacker].drawMonster();
    drawMonsterAddictionalData();
}

void Fight::drawMonsterAddictionalData() {
    char *endLine = "     | \n";
    char *l1s1 = "\t---------------------------------------------------------------------------------------------------- \n";
    char *l2s1 = "\t|  Nazwa: ";
    char *l2s2 = "                                           Odleglosc: ";
    char *l3s1 = "\t|                                                                             Poziom:         ";
    char *l4s1 = "\t|                                                                                             ";
    char *l5s1 = "\t|                                                                                             ";
    char *l6s1 = "\t|  ";
    char *l6s2 = "                                         ";
    char *l7s1 = "\t|  ";
    char *l7s2 = "                         Przeciwnik: ";
    std::cout
    << l1s1
    << l2s1 << FightData.monsters[FightData.actuallAttacker].getMonsterName(25, true) << l2s2 << FightData.monsters[FightData.actuallAttacker].getMonsterShowUpRange(5, true) << endLine
    << l3s1 << endLine
    << l4s1 << endLine
    << l5s1 << endLine
    << l6s1 << getSpecialMessageFight(0, 50, true) << l6s2 << endLine
    << l7s1 << getSpecialMessageFight(1, 50, true) << l7s2 << FightData.actuallAttacker+1 << "/" << FightData.enemiesNumber+1 << " " << endLine
    << l1s1 << "\n";
}



int Fight::getMonsterID(float lvl) {
    int id = 0, currentIdLvl_min,  currentIdLvl_max;
    for (int i = 0; i < 20; i++) {
        id = rand()%(MonstersData.MonstersArrayIndex);
        std::cout << id << std::endl;
        if (i == 19) return id;

        currentIdLvl_min = MonstersData.MonstersArray[id].min_lvl;
        currentIdLvl_max = MonstersData.MonstersArray[id].max_lvl;

        if (currentIdLvl_min <= lvl && currentIdLvl_max >= lvl) return id;

    }
    return 0;
}

std::string Fight::getSpecialMessageFight(int which, int lenght, bool overwrite) {
    if (lenght == -1) return GameVariables.specialMesseges[which];
    if (lenght < GameVariables.specialMesseges[which].length()) {
        if (overwrite) return GameVariables.specialMesseges[which].substr(0, lenght);
        return GameVariables.specialMesseges[which];
    }
    return GameVariables.specialMesseges[which] + std::string(lenght-GameVariables.specialMesseges[which].length(), 32);
}
