#ifndef __GAME_H
#define __GAME_H

#include <string>
#include "player.h"

extern Player player;

namespace MainGame {
    namespace menu {
        void menu();
        void loadGame();
        void saveGame();
        void newGame();
        void options();
        void menuFail();
    }
    void generateWord();
    void drawGame();
    int useCommand(std::string command);
    namespace getData {
        bool getDataInBattle();
        int getLevel();
        float getDifficulty();
        int getDataBoard(int y, int x);
        void setSpecialMessages(std::string text, int row);
    }
};
#endif
