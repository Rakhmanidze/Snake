#ifndef MENU_H
#define MENU_H

#include <string>
#include "../include/snakegame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Represents the menu for the Snake game, allowing users to navigate options and view instructions.
 */
class Menu {
    public:
        /**
         * Constructor to initialize the Menu with a reference to the SnakeGame.
         * @param game Reference to the SnakeGame instance.
         */
        Menu(SnakeGame& game);

        /**
         * Displays the main menu options to the user.
         */
        void display();

        /**
         * Displays the game instructions to help the player understand the rules.
         */
        void displayInstructions() const;

    private:
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance for managing game state */

        /**
         * Prompts the user for input and validates it against the specified range.
         * @param text The prompt message to display.
         * @param min The minimum valid input value.
         * @param max The maximum valid input value.
         * @return The validated input from the user.
         */
        int getValidatedInput(const std::string& text, int min, int max);
};

#endif
