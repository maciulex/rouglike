#include <iostream>

#include "../../headers/utilitis/board.hpp"
#include "../../headers/global.hpp"
#include "../../headers/player.hpp"
#include "../../headers/utilitis/hud.hpp"
#include "../../headers/fight/fight.hpp"
#include "../../lib/color.hpp"

using namespace std;

extern Player player;
extern Player::PlayerVariables variablesPlayer;

void Board::drawGame() {
    drawBlank();
    switch (GameVariables.hud) {
        case 1:
            player.drawInventory();
            Hud::drawHud();
            return;
        break;
        case 6:
            GameVariables.hud = 3;
            drawGame();
            return;
        break;
    }
    if (GameVariables.battle) {
        Fight::drawActuallMonster();
    } else {
        Board::drawBoard();
    }
    Hud::drawHud();
}
void Board::drawBlank() {
    string blank = "";
    for (int i = 0; i < 40; i++) {
        blank += "\n";
    }
    cout << blank;
}
void Board::drawBoard() {
    int height = GameVariables.height, width = GameVariables.width;
    if (GameVariables.fastDrawBoard) {

    } else {
        for (int y = 0; y < height; y++) {
            cout << "\t";
            for (int x = 0; x < width; x++) {
                if (y == variablesPlayer.y && x == variablesPlayer.x) {
                    cout << dye::aqua('P');
                    continue;
                }
                switch(GameVariables.board[y][x]) {
                    case -1:
                        cout << '-';
                    break;
                    case -2:
                        cout << '|';
                    break;
                    case 0:
                        cout << " ";
                    break;
                    case 1:
                        cout << char(219);
                    break;
                    case 2:
                        cout << dye::yellow(char(219));
                    break;
                }
            }
            switch (y) {
                case 25:
                    cout << "\t" << GameVariables.specialMesseges[0];
                    GameVariables.specialMesseges[0] = "";
                break;
                case 26:
                    cout << "\t" << GameVariables.specialMesseges[1];
                    GameVariables.specialMesseges[1] = "";
                break;
                case 27:
                    cout << "\t" << GameVariables.specialMesseges[2];
                    GameVariables.specialMesseges[2] = "";
                break;
                case 28:
                    cout << "\t" << GameVariables.specialMesseges[3];
                    GameVariables.specialMesseges[3] = "";
                break;
                case 29:
                    cout << "\t" << GameVariables.specialMesseges[4];
                    GameVariables.specialMesseges[4] = "";
                break;
            }
            cout<<endl;
        }
    }
};
