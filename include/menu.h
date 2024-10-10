#ifndef MENU_H
#define MENU_H

#include <string>
#include "../include/snakegame.h"

class SnakeGame;

class Menu {
    public:
        Menu(SnakeGame& game);
        void display();
        void displayInstructions() const;

    private:
        SnakeGame& snakeGame;
        int getValidatedInput(const std::string& text, int min, int max);
};

#endif
