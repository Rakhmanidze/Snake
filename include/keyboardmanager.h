#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "direction.h"
#include "../include/snakegame.h"

class SnakeGame;

class KeyboardManager {
    public:
        KeyboardManager(SnakeGame& game);
        Direction getDirection();
        void update();

    private:
        Direction currentDirection;
        SnakeGame& snakeGame;
};

#endif //KEYBOARDMANAGER_H
