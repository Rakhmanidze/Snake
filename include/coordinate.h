#ifndef COORDINATE_H
#define COORDINATE_H

/**
 * Class representing a coordinate with x and y values.
 */
class Coordinate {
public:
    int x, y;

    /**
     * Constructor to initialize coordinates with default values.
     *
     * @param xVal The value for the x-coordinate (default is -1).
     * @param yVal The value for the y-coordinate (default is -1).
     */
    Coordinate(int xVal = -1, int yVal = -1) : x(xVal), y(yVal) {}

    /**
     * Overloaded equality operator to compare two Coordinate objects.
     *
     * @param other The other Coordinate object to compare against.
     * @return true if both coordinates are equal, false otherwise.
     */
    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }
};

#endif
