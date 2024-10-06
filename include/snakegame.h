#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "../include/gamestate.h"

class Menu;

class SnakeGame {
    public:
        void run();
        void setCurrentState(GameState state);
    private:
        Menu* menu;
        GameState currentState;
        void updateMenu();
};

#endif
