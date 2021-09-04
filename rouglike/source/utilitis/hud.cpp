#include <iostream>

#include "../../headers/utilitis/hud.hpp"

#include "../../headers/global.hpp"
#include "../../headers/player.hpp"
#include "../../lib/color2.hpp"

using namespace std;

extern Player player;

void Hud::drawHud() {
    char *endLine = "     | \n";
    char *l1s1 = "\t---------------------------------------------------------------------------------------------------- \n";
    char *l2s1 = "\t|                                                                                    hp: ";
    char *l3s1 = "\t|                                                                                        ";
    char *l4s1 = "\t|   |------------| |------------| |------------| |------------| |------------|       mp: ";
    char *l5s1;
    char *l6s1 = "\t|   |------------| |------------| |------------| |------------| |------------|       sp: ";
    char *l7s1 = "\t|                                                                                    st: ";
    char *l8s1 = "\t|                                                                                    it: ";
    // 0 = standard 1 - ekwipunek 2 - wyrzucenie broni, 3 - walka main menu, 4 - menu wojownika, 5 - menu maga
    switch(GameVariables.hud) {
        case 0:
            l5s1 = "\t|   | Walcz      | | Cwicz      | | Przedmioty | | Statystyki | |    Menu    |           ";
        break;
        case 1:
            l5s1 = "\t|   | Uzyj       | | Wyrzuc     | | Szczegoly  | |  <  /  >   | |   Powrot   |           ";
        break;
        case 2:
            l5s1 = "\t|   | Wyrzuc     | | Szczegoly  | |     <      | |      >     | |   Powrot   |           ";
        break;
        case 3:
            l5s1 = "\t|   | Wojownik   | | Mag        | | Uciekaj    | | Przedmioty | |   Wiecej   |           ";
        break;
        case 4:
            l5s1 = "\t|   | Atak       | | Obrona     | | Odnow sily | | Przedmioty | |   Powrot   |           ";
        break;
        case 5:
            l5s1 = "\t|   | Atak       | | Obrona     | | Odnow mane | | Przedmioty | |   Powrot   |           ";
        break;
        case 6:
            l5s1 = "\t|   | Uzyj       | | Zapomnij   | | Cwicz      | | Przenies   | |   Powrot   |           ";
        break;
    }
    cout << string(l1s1)+l2s1 << dye::red(player.variables.healthString[0])<<player.variables.healthString[1] << string(endLine)+l3s1
    << dye::red(player.variables.healthString[2]) << player.variables.healthString[3] << endLine
    << l4s1 << dye::blue(player.variables.manaString[0]) << player.variables.manaString[1] << endLine << l5s1 << player.variables.manaString[2] << player.variables.manaString[3]
    << endLine << l6s1 << player.variables.speedString << endLine << l7s1 << player.variables.strengeString << endLine << l8s1 << player.variables.itelligenceString << endLine << l1s1;
}
