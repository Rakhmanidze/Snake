#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "direction.h"
#include "../include/snakegame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Manages keyboard input for controlling the snake's direction.
 */
class KeyboardManager {
    public:
        /**
        * Constructor to initialize the KeyboardManager with a reference to the SnakeGame.
        * @param game Reference to the SnakeGame instance.
        */
        KeyboardManager(SnakeGame& game);

        /**
         * Gets the current direction of the snake.
         * @return The current direction of the snake.
         */
        Direction getDirection();

        /**
         * Sets a new direction for the snake.
         * @param newDirection The new direction to set.
         */
        void setDirection(Direction newDirection);

        /**
         * Updates the keyboard state, handling any input.
         */
        void update();

    private:
        Direction currentDirection;
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance */
};

#endif
