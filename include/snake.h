#ifndef SNAKE_H
#define SNAKE_H

#include "../include/gamedata.h"
#include <vector>
#include "coordinate.h"

/**
 *  Forward declaration of the Food class.
 */
class Food;

/**
 * Represents the Snake in the game, managing its position, movement, and interactions
 * with food and the game environment.
 */
class Snake {
    public:
        /**
         * Constructor to initialize a new Snake instance.
         */
        Snake();

        /**
         * Updates the state of the snake, including movement and collision detection.
         * @return An integer indicating the status of the update (0 if alive, 1 if dead).
         */
        int update();

        /**
         * Retrieves the current body segments of the snake.
         * @return A vector containing the coordinates of the snake's body segments.
         */
        std::vector<Coordinate> getBody() const;

        /**
         * Makes the snake eat the given food, increasing its score and size.
         */
        void eat();

        /**
         * Retrieves the current score of the snake.
         * @return The current score as an integer.
         */
        int getScore() const;

    private:
        bool alive; /** Indicates whether the snake is alive */
        int score; /** The current score of the snake */
        std::vector<Coordinate> snake; /** The body segments of the snake */

        /**
         * Initializes the snake's starting position and size.
         */
        void createSnake();

        /**
         * Moves the snake in the current direction and handles collision detection.
         * @return An integer indicating the status of the move (0 if successful, 1 if dead).
         */
        int move();

        /**
         * Increases the size of the snake by adding a new segment to its body.
         */
        void grow();

        /**
         * Marks the snake as dead, ending the game for this snake.
         */
        void die();
};

#endif
