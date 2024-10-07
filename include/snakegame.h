#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "../include/gamestate.h"

class Menu;
class Playing;

class SnakeGame {
    public:
        void run();
        void setCurrentState(GameState state);
    private:
        Menu* menu;
        Playing* playing;
        GameState currentState;
        void updateMenu();
        void updatePlaying();
};

#endif
