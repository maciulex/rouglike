#ifndef __PLAYER_H
#define __PLAYER_H

#include <string>

class Player {
    // inventory [0] id, [1] type {0 - melee, 1 - range, 2- heal 3 buff};
     public:
        struct PlayerVariables{
            int x, y, maxHealth = 0, maxMana = 0, coins = 0, strenge = 0, speed = 0, itelligence = 0, eyes = 10, equipedIteamId = 0; float mana = 0, health = 0;
            int specialStatus[150][2], attacksWarrior[50], attacksMagican[50];
            int inventory[150][2], inventoryOnePageItemAmount = 25, actualPage = 1, inventorySize;
            std::string healthString[4], manaString[4], strengeString, speedString, itelligenceString, coinsString;
        } variables;

        //player.cpp
        Player();
        void hitWall(int strength);
        int specialStatusFreeIndex();
        void restoreBlockedStatuses(int which);
        bool isWeaponFromInventory(int index);

        //player/update.cpp
        void updateHP(int x);
        void updateMP(int x);
        void updateST(int x);
        void updateSP(int x);
        void updateIT(int x);
        void updateCOIN(int x);
        void updateVision(int x);
        void playerMove(int x = 0, int y = 0, bool draw = true);

        //player/attacks.cpp
        void drawAttacksWarrior();
        void drawAttacksMagican();
        int getWarriorAttackFreeIndeks();
        int getMagicanAttackFreeIndeks();

        //player/inventory.cpp
        void drawInventory();
        void drawMoreDataAbout(int index);
        void dropIteam(int index);
        void dropIteam(std::string index);
        void dropItemForNewOne();
        void dropItemForNewOne_draw_only();
        void finalizeEffect(int effect, bool pernament = true, int latency = 0);
        std::string getAcutalUseItemName();
        int getInventoryFreeIndex();
        bool iteamIndexValidation(int index);
        bool tryUseIteam(int index);
};
#endif
