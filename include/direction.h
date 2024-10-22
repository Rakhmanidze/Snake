#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * Enum class representing the possible directions for movement.
 */
enum class Direction {
    RIGHT,
    LEFT,
    UP,
    DOWN
};

/**
 * Declare an external variable to hold the current direction.
 */
extern Direction direction;

#endif
