#include <string>

class Player {
     public:
        struct PlayerVariables {
            int x, y, maxHealth = 0, maxMana = 0, coins = 0, strenge = 0, speed = 0, itelligence = 0; float mana = 0, health = 0;
            int specialStatus[150][150] = {-1}, inventory[100], attacksWarrior[50][50] = {0}, attacksMagican[50][50] = {0};
            std::string healthString[4], manaString[4], strengeString, speedString, itelligenceString, coinsString;
        } variables;
        void updateHP(int x);
        void updateMP(int x);
        void updateST(int x);
        void updateSP(int x);
        void updateIT(int x);
        void updateCOIN(int x);
        Player();
};
