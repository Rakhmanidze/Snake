#ifndef RENDER_H
#define RENDER_H

#include "../include/snakegame.h"

class SnakeGame;

class Render {
    public:
        Render(SnakeGame& snakeGame);
        void render() const;
    private:
        SnakeGame& snakeGame;
};
#endif
