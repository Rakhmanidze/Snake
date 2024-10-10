#ifndef SNAKE_H
#define SNAKE_H

#include "../include/gamedata.h"
#include <vector>
#include "coordinate.h"

class Snake {
    public:
        // Snake();
        void move();
        void grow();
        void eat();
        void die();
        bool isAlive() const;
        int getLength() const;
        int getScore() const;
        std::vector<Coordinate>& getBody() const;
    private:
        bool alive;
        int length;
        int score;
        std::vector<Coordinate> snake;
        GameData::Direction currentDirection;
        int speed;
};

#endif
