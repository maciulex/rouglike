#ifndef __GLOBALS_H
#define __GLOBALS_H

#include "iteams.h"
    bool ProgramOpenState = true;
    int InputOutputDirection = 1;
    struct globalsGameVariables {
        int **board, width, height, hud = 0, level = 0;
        float difficulty;
        bool fastDrawBoard = false, battle = false;
        std::string seed, specialMesseges[5] = {""};
    } GameVariables;
#endif
