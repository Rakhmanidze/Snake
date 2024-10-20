#ifndef FOOD_H
#define FOOD_H

#include "coordinate.h"
#include "snake.h"

class Food {
    public:
        Food();
        void spawn(const std::vector<Coordinate>& snakeBody);
        void remove();
        bool isExist() const;
        Coordinate getCoordinate() const;
    private:
        bool exists;
        Coordinate foodXY;
        bool isFoodOnSnake(const std::vector<Coordinate>& snakeBody) const;
};

#endif