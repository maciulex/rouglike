#ifndef __GAME_H
#define __GAME_H

#include <string>

namespace MainGame {
    struct{
        int **board, width, height, hud = 0;
        float difficulty;
        bool fastDrawBoard = false, battle = false;
        std::string seed, specialMesseges[5] = {""};
    } GameVariables;
    namespace menu {
        void menu();
        void loadGame();
        void saveGame();
        void newGame();
        void options();
        void menuFail();
    }
    void generateWord();
    void drawBoard();
    void DrawBlank();
    void drawHud();
    void drawGame();
    int useCommand(std::string command);
    namespace getData {
        bool getDataInBattle();
        int getDataBoard(int y, int x);
        void setSpecialMessages(std::string text, int row);
    }
};
#endif
