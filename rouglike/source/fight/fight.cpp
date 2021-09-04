#include "../../headers/fight/fight.hpp"

#include "../../headers/game.hpp"
#include "../../headers/global.hpp"
#include "../../lib/color3.hpp"
#include "../../headers/fight/monsters.hpp"
#include "../../headers/utilitis/board.hpp"
#include "../../headers/player.hpp"
#include "../../headers/fight/attacks.hpp"
#include "../../headers/input.hpp"

#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <thread>

Fight::FightDataStruct FightData;

extern Monsters::MonsterDataStruct MonstersData;
extern Attacks::AttacksDataStruct AttacksData;
extern Player player;

void Fight::engineFight() {
    prepareFight();
    Board::drawGame();
//    while (GameVariables.battle) {
//        if (FightData.enemiesNumber == 0) {
//            endBattle();
//        }
//    }
    //fight.detach();
}

void Fight::endBattle() {
    GameVariables.battle = false;
    GameVariables.hud = 0;
    Game::setSpecialMessages("Walka zakonczona!", 0);
}

void Fight::nextMonster() {
    FightData.actuallAttacker += 1;
    if (FightData.actuallAttacker == FightData.enemiesNumber) FightData.actuallAttacker = 0;
    Board::drawGame();
}

void Fight::killMonster(int indeks) {
    if (indeks < 0 || indeks >= FightData.enemiesNumber) return;

    for (int i = indeks; i < FightData.enemiesNumber-1; i++) {
        FightData.monsters[i] = FightData.monsters[i+1];
    }
    Game::setSpecialMessages("Potwor zostal zabity!", 0);
    FightData.enemiesNumber -= 1;
    nextMonster();
}

void Fight::generateFightCombination() {
    for (int i = 0; i < 32; i++) FightData.combination[i] = 0;

    FightData.amountOfCombintaions = GameVariables.difficulty*((FightData.endDifficulty > 15) ? 13 : FightData.endDifficulty);

    for (int i = 0; i < FightData.amountOfCombintaions; i++) {
        FightData.combination[i] = rand()%4+1;
    }
}

void Fight::generateTimeCombination() {
    switch (GameVariables.difficulty) {
        case 1:
            FightData.timeForOne = 1500;
        break;
        case 2:
            FightData.timeForOne = 950;
        break;
        case 3:
            FightData.timeForOne = 700;
        break;
        case 4:
            FightData.timeForOne = 350;
        break;
        case 5:
            FightData.timeForOne = 200;
        break;
        default:
            FightData.timeForOne = 696;
        break;
    }
}

void Fight::addFightDirectory(int directory) {
    if (directory < 1 || directory > 4) return;
    if (FightData.combinationIndeks >= 32) return;

    FightData.acutalInputCombination[FightData.combinationIndeks] = directory;

    FightData.combinationIndeks += 1;
}

void Fight::prepareFight(float localDifficultyModifier) {
    srand(time(NULL));
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
        localMonster.lvl = rand()%localMonster.max_lvl+localMonster.min_lvl;
        if (GameVariables.plusMonsterRand) {
            float lvlModyfier = .5;
            localMonster.hp          = localMonster.hp          + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.mana        = localMonster.mana        + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.baseDef     = localMonster.baseDef     + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.distanceDef = localMonster.distanceDef + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.meleeDef    = localMonster.meleeDef    + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.speed       = localMonster.speed       + ( (rand()%localMonster.lvl) * lvlModyfier);
            localMonster.strenght    = localMonster.strenght    + ( (rand()%localMonster.lvl) * lvlModyfier);
        }
//        for (int i = 0; i < 100; i++) {
//            std::cout << (rand()%localMonster.showUpRange+1)+player.variables.eyes/(rand()%player.variables.eyes+1) << std::endl;
//        }
//        system("pause");


        localMonster.showUpRange = (rand()%localMonster.showUpRange+1)+player.variables.eyes/(rand()%player.variables.eyes+1);


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
    char *l3s1 = "\t|                                                                             Poziom: ";
    char *l4s1 = "\t|  ";
    char *l5s1 = "\t|                                                                                             ";
    char *l6s1 = "\t|  ";
    char *l6s2 = "                                         ";
    char *l7s1 = "\t|  ";
    char *l7s2 = "                         Przeciwnik: ";
    std::cout
    << l1s1
    << l2s1 << FightData.monsters[FightData.actuallAttacker].getMonsterName(25, true) << l2s2 << FightData.monsters[FightData.actuallAttacker].getMonsterShowUpRange(5, true) << endLine
    << l3s1 << FightData.monsters[FightData.actuallAttacker].getMonsterLevel(8, true) << endLine
    << l4s1; drawMonsterHp(); std::cout << endLine
    << l5s1 << endLine
    << l6s1 << getSpecialMessageFight(0, 50, true) << l6s2 << endLine
    << l7s1 << getSpecialMessageFight(1, 50, true) << l7s2 << FightData.actuallAttacker+1 << "/" << FightData.enemiesNumber << " " << endLine
    << l1s1 << "\n";
}

void Fight::drawMonsterHp() {
    int length = 9;
    std::cout << "HP: |";
    for (int i = 0; i < 30; i++) {
        if (FightData.monsters[FightData.actuallAttacker].hp < i) break;
        std::cout << " " << dye::red(char(219));
        length += 2;
    }
    if (FightData.monsters[FightData.actuallAttacker].hp <= 30) {
        std::cout << " |   ";
    } else {
        std::cout << " |" << dye::red("+") << "| ";
    }
    if (length < 90) {
        std::cout << std::string(90-length, 32);
    }
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

void Fight::getAttack(int attackType) {
    //attackType 0 - wojownik, 1 - mag
    int attack[2];
    attack[0] = attackType;
    std::cout << "\n\nWybierz atak: ";
    std::cin >> attack[1];
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        getAttack(attackType);
        return;
    }
    switch (attackType) {
        case 0:
            if (AttacksData.MeleeAttacksIndeks <= attack[1] || attack[1] < 0) attack[1] = -1;
        break;
        case 1:
            if (AttacksData.RangeAttacksIndeks <= attack[1] || attack[1] < 0) attack[1] = -1;
        break;
    }
    FightData.attack[0] = attack[0];
    FightData.attack[1] = attack[1];
    battleGo();
}

void Fight::battleGo() {
    BlockInputThread = true;
    FightData.fastEndEnter = false;
    FightData.combinationIndeks = 0;
    std::thread FightInput(InputFight);
    generateFightCombination();
    generateTimeCombination();
    std::cout << "\nSzybko!:\n";
    for (int i = 0; i < FightData.amountOfCombintaions; i++) {
        switch (FightData.combination[i]) {
            case 1:
                std::cout << (char)16;
            break;
            case 2:
                std::cout << (char)17;
            break;
            case 3:
                std::cout << (char)30;
            break;
            case 4:
                std::cout << (char)31;
            break;
            default:
                i=99999;
            break;
        }
    }
    std::cout << "\n";\
    int timePass = 0, time = FightData.timeForOne*FightData.amountOfCombintaions;
    while (timePass <= time) {
        if (FightData.fastEndEnter) {timePass = time+1; break;};
        timePass += 20;
        Sleep(20);
    }
    generateResult();
    BlockInputThread = false;
    FightInput.detach();
    system("pause");
}

void Fight::generateResult() {
    double resultPercentage;
    int good = 0, bad = 0, all = FightData.amountOfCombintaions;
    for (int i = 0; i < FightData.amountOfCombintaions; i++) {
        if (FightData.combination[i] == FightData.acutalInputCombination[i]) good += 1;
        else bad += 1;
    }
    resultPercentage = ((double)good/(double)all)*100;
    std::cout << "Result: " << std::to_string(resultPercentage) << ", Good = " << good << ", Bad = " << bad << ", all = " << all;
    system("pause");
}

std::string Fight::getSpecialMessageFight(int which, int lenght, bool overwrite) {
    std::string specialMessage = GameVariables.specialMesseges[which];
    GameVariables.specialMesseges[which] = "";
    if (lenght == -1) return specialMessage;
    if (lenght < specialMessage.length()) {
        if (overwrite) return specialMessage.substr(0, lenght);
        return specialMessage;
    }
    return specialMessage + std::string(lenght-specialMessage.length(), 32);
}
