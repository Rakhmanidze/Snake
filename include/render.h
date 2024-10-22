#ifndef RENDER_H
#define RENDER_H

#include "../include/snakegame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Responsible for rendering the game state to the user, including displaying the game map,
 * snake, and other game elements on the screen.
 */
class Render {
    public:
        /**
         * Constructor to initialize the Render instance with a reference to the SnakeGame.
         * @param snakeGame Reference to the SnakeGame instance used for rendering.
         */
        Render(SnakeGame& snakeGame);

        /**
         * Renders the current game state to the console, including the map and any game elements.
         */
        void render() const;

    private:
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance for accessing game state */
};

#endif
