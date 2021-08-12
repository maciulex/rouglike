#ifndef GAME_HPP
#define GAME_HPP
#include <string>
    namespace Game {
        void generateWord();
        void setSpecialMessages(std::string text, int row);
        float getRarity();
        float getDifficulty();
    }
#endif
