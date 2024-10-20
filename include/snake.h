#ifndef SNAKE_H
#define SNAKE_H

#include "../include/gamedata.h"
#include <vector>
#include "coordinate.h"
#include "direction.h"
#include "food.h"

class Food;

class Snake {
    public:
        Snake();
        int update();
        void setDirection(Direction direction);
        std::vector<Coordinate> getBody() const;
        void eat(Food& food);
        int getScore() const;

    private:
        bool alive;
        int score;
        std::vector<Coordinate> snake;
        Direction currentDirection;
        int speed;
        void createSnake();
        int move();
        void grow();
        void die();
};

#endif
