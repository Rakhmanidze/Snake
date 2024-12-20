#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../include/snakeGame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Manages keyboard input for controlling the snake's direction and Menu logic.
 */
class KeyboardManager {
    public:
        /**
        * Constructor to initialize the KeyboardManager with a reference to the SnakeGame.
        * @param game Reference to the SnakeGame instance.
        */
        KeyboardManager(SnakeGame& game);

        /**
         * Sets a new direction for the snake.
         * @param newDirection The new direction to set.
         */
        void setLastInputDirection(int newDirection);

        /**
         * Retrieves the last score of the snake.
         * @return The current score as an integer.
         */
        int getLastInputDirection();

        /**
         * Handles input and updates the keyboard state based on the current game state.
         */
        void handleInput();

    private:
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance. */
        int lastInputDirection; /** The last input direction for the snake. */
};

#endif
