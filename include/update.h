#ifndef UPDATE_H
#define UPDATE_H

#include "../include/snakegame.h"

class SnakeGame;

class Update {
    public:
        Update(SnakeGame& snakeGame);
        void update() const;
    private:
        SnakeGame& snakeGame;
};

#endif
