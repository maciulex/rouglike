

class MainGameClass {
    int board, width, height;
    bool randomSeed;

    void generateWord();
    void drawWord();
    void drawHud();

    public:
        void loadGame();
        void saveGame();
        void newGame();

};
