#ifndef FOOD_H
#define FOOD_H

#include "coordinate.h"
#include "snake.h"

/**
 * Class representing food in the game.
 * The food can be spawned, removed, and checked for existence.
 */
class Food {
    public:
        /**
        * Default constructor to initialize the Food object.
        */
        Food();

        /**
        * Spawns the food at a random location not occupied by the snake.
        * @param snakeBody A vector containing the coordinates of the snake's body segments.
        */
        void spawn(const std::vector<Coordinate>& snakeBody);

        /**
         * Removes the food from the game, marking it as nonexistent.
         */
        void remove();

        /**
         * Checks if the food currently exists in the game.
         * @return true if the food exists; false otherwise.
         */
        bool isExist() const;

        /**
         * Gets the current coordinates of the food.
         * @return The coordinates of the food as a Coordinate object.
         */
        Coordinate getCoordinate() const;

    private:
        bool exists; ///< Indicates whether the food is currently in existence.
        Coordinate foodXY; ///< The coordinates of the food.

        /**
        * Checks if the food's coordinates overlap with any part of the snake's body.
        * @param snakeBody A vector containing the coordinates of the snake's body segments.
        * @return true if the food is located on the snake; false otherwise.
        */
        bool isFoodOnSnake(const std::vector<Coordinate>& snakeBody) const;
};

#endif