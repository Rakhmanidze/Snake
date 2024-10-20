#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "../include/gamestate.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/update.h"

class Menu;
class Playing;
class Render;
class Update;

class SnakeGame {
    public:
        void run();
        void setCurrentState(GameState state);
        Menu* getMenu();
        Playing* getPlaying();

    private:
        Menu* menu;
        Playing* playing;
        Render* render;
        Update* update;

};

#endif
