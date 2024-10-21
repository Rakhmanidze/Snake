#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "../include/gamestate.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/update.h"
#include "../include/keyboardmanager.h"

class Menu;
class Playing;
class Render;
class Update;
class KeyboardManager;

class SnakeGame {
    public:
        void run();
        static void setCurrentState(GameState state);
        Menu* getMenu() const;
        Playing* getPlaying() const;
        KeyboardManager* getKeyboardManager() const;

    private:
        Menu* menu;
        Playing* playing;
        Render* render;
        Update* update;
        KeyboardManager* keyboardManager;

};

#endif
