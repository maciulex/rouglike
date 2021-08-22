#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
class Player {
    // inventory [0] id, [1] type {0 - melee, 1 - range, };
     public:
        struct PlayerVariables{
            int x, y, maxHealth = 0, maxMana = 0, coins = 0, strenge = 0, speed = 0, itelligence = 0, eyes = 0; float mana = 0, health = 0;
            int specialStatus[150][2] = {-1}, attacksWarrior[50] = {0}, attacksMagican[50] = {0};
            int inventory[150][2] = {0}, inventoryOnePageItemAmount = 25, actualPage = 1, inventorySize;
            std::string healthString[4], manaString[4], strengeString, speedString, itelligenceString, coinsString;
        } variables;
        void updateHP(int x);
        void updateMP(int x);
        void updateST(int x);
        void updateSP(int x);
        void updateIT(int x);
        void updateCOIN(int x);
        void updateVision(int x);
        void hitWall(int strength);
        void playerMove(int x = 0, int y = 0, bool draw = true);
        int specialStatusFreeIndex();
        void restoreBlockedStatuses(int which);
        int getInventoryFreeIndex();
        void drawInventory();
        void dropItemForNewOne();
        void dropItemForNewOne_draw_only();
        void drawMoreDataAbout(int index);
        void dropIteam(int index);
        void dropIteam(std::string index);
        bool tryUseIteam(int index);
        void finalizeEffect(int effect, bool pernament = true, int latency = 0);
        bool iteamIndexValidation(int index);
        Player();
};
#endif
