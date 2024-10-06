#ifndef MENU_H
#define MENU_H

#include <string>
#include "../include/snakegame.h"

class SnakeGame;

class Menu {
    public:
        Menu(SnakeGame& game);
        void displayMenu();
        void displayInstructions() const;

    private:
        SnakeGame& game;
        int getValidatedInput(const std::string& text, int min, int max);
};

#endif
