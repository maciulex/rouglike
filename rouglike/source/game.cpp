#include "../headers/game.hpp"
#include "../headers/global.hpp"
#include "../headers/player.hpp"

#include <ctime>
#include <cstdlib>

extern Player player;

void Game::generateWord() {
////    cout << GameVariables.width;
    if (GameVariables.seed == "falseNotNULLSeed"){
        srand(time(NULL));
    } else {
        srand(std::hash<std::string>{}(GameVariables.seed));
    }
    int height = GameVariables.height, width = GameVariables.width;
    GameVariables.board = new int *[height];
    for (int y = 0; y < height; y++) {
        GameVariables.board[y] = new int [width];
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height-1) {
                GameVariables.board[y][x] = -1;
            } else if (x == 0 || x == width-1) {
                GameVariables.board[y][x] = -2;
            } else {
                int r;
                if (y > 15 && y < 35 && x > 30 && x < 70) {
                    r = rand()%5+1;
                } else {
                    r = rand()%3+1;
                }
                if (r!=1) {
                    GameVariables.board[y][x] = 0;
                } else {
                    GameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (GameVariables.board[y][x] == -1 || GameVariables.board[y][x] == -2) {
                continue;
            }
            for (int smooth = 0; smooth < 1; smooth++) {
                int wall = 0;
                for (int Sy = -1; Sy <= 1; Sy++) {
                    for (int Sx = -1; Sx <= 1; Sx++) {
                        if (GameVariables.board[y+Sy][x+Sx] != 0) {
                            wall += 1;
                        }
                    }
                }
                if (wall > 5) {
                    GameVariables.board[y][x] = 1;
                }
            }
        }
    }
    for (int y = -3; y <= 3; y++) {
        for (int x = -3; x <= 3; x++) {
            if ((y == -3 || y == 3) && (x == -3 || x == 3)) {
                GameVariables.board[height/2+y][width/2+x] = 2;
            } else {
                GameVariables.board[height/2+y][width/2+x] = 0;
            }
        }
    }
    GameVariables.level += 1;
    player.variables.x = width/2;
    player.variables.y = height/2;
}
void Game::setSpecialMessages(std::string text, int row) {
    GameVariables.specialMesseges[row] = text;
}
float Game::getRarity() {
    int luck = rand()%100;
    if (luck == 100) luck = 10;
    else if (luck > 75) luck = 3;
    else if (luck > 50) luck = 2;
    else if (luck > 30) luck = 1;
    else luck = 0;

    if (GameVariables.level < 10) {
        return GameVariables.level * getDifficulty() +(rand()%4*.5) + luck;
    } else {
        return GameVariables.level * getDifficulty() +(rand()%8*.5) + luck;
    }
}
float Game::getDifficulty() {
    if (GameVariables.level < 10) {
        switch (GameVariables.difficulty) {
            case 1:
                return .5;
            case 2:
                return .75;
            case 3:
                return 1;
            case 4:
                return 1.25;
            case 5:
                return 1.5;
        }
    } else {
            switch (GameVariables.difficulty) {
            case 1:
                return .8;
            case 2:
                return .85;
            case 3:
                return 1;
            case 4:
                return 1.20;
            case 5:
                return 1.35;
        }
    }
}
