#ifndef RENDER_H
#define RENDER_H

#include "../include/snakegame.h"

class SnakeGame;

class Render {
    public:
        Render(SnakeGame& snakeGame);
        void render();
    private:
        SnakeGame& snakeGame;
};
#endif
