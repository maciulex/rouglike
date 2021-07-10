#include <string>

namespace MainGame {
    struct GameVariables {
        int **board, width, height;
        float difficulty;
        bool fastDrawBoard = false;
        std::string seed, specialMesseges[5] = {""};
    };
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
    void drawHud();
};
