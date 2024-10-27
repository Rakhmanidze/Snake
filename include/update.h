#ifndef UPDATE_H
#define UPDATE_H

#include "../include/snakeGame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Handles the update logic for the Snake game.
 */
class Update {
    public:
        /**
         * Constructs an Update instance with a reference to the SnakeGame.
         * @param snakeGame Reference to the main game object for updating game state.
         */
        Update(SnakeGame& snakeGame);

        /**
         * Performs the update logic for the game.
         * This function is responsible for updating the game state, such as moving the snake and checking for collisions.
         */
        void update() const;

    private:
        SnakeGame& snakeGame; /** Reference to the main game object for accessing game state and functions. */
};

#endif
