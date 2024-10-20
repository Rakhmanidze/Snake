#ifndef SNAKE_H
#define SNAKE_H

#include "../include/gamedata.h"
#include <vector>
#include "coordinate.h"
#include "gamestate.h"

class Snake {
    public:
        Snake();
        int update();
        bool isAlive() const;
        int getLength() const;
        int getScore() const;

        std::vector<Coordinate> getBody() const;
    private:
        bool alive;
        int length;
        int score;
        std::vector<Coordinate> snake;
        GameState currentDirection;
        int speed;
        void createSnake();
        int move();
        void grow();
        void eat();
        void die();
};

#endif
