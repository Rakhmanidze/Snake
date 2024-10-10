#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate {
    int x, y;

    Coordinate(int xVal = -1, int yVal = -1) : x(xVal), y(yVal) {}

    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }
};

#endif
