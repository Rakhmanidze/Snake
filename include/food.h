#ifndef FOOD_H
#define FOOD_H

#include "coordinate.h"

class Food {
    public:
        // Food();
        void spawn();
        void remove();
        bool isExist() const;
        Coordinate getCoordinate() const;
    private:
        bool exists;
        Coordinate foodXY;
};

#endif