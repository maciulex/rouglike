#include "../../../headers/game.h"

bool MainGame::getData::getDataInBattle() {
    return GameVariables.battle;
}

int MainGame::getData::getDataBoard(int y, int x) {
    return GameVariables.board[y][x];
}
int MainGame::getData::getLevel() {
    return GameVariables.level;
}
float MainGame::getData::getDifficulty() {
    return GameVariables.difficulty;
}
void MainGame::getData::setSpecialMessages(std::string text, int row) {
    GameVariables.specialMesseges[row] = text;
}
