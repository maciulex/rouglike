#ifndef GLOBAL_H
#define GLOBAL_H
    #include <string>
    class globalsGameVariables;


    extern bool ProgramOpenState;
    extern bool BlockInputThread;
    extern int InputOutputDirection;
    extern globalsGameVariables GameVariables;


    class globalsGameVariables {
        public:
        int **board, width, height, hud = 0, level = 0, difficulty;
        bool fastDrawBoard = false, battle = false, plusMonsterRand = true;
        std::string seed, specialMesseges[5] = {""};
    };
#endif
