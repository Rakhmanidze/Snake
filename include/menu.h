#ifndef MENU_H
#define MENU_H

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
         * Sets whether the instructions should be displayed.
         * @param value A boolean indicating if instructions should be displayed (true) or not (false).
         */
        void setIntructions(bool value);

        /**
         * Sets whether the menu has been displayed.
         * @param value A boolean indicating if the menu has been displayed (true) or not (false).
         */
        void setMenuDisplayed(bool value);

    private:
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance for managing game state */
        bool isInstructionsDisplayed = false; /** Flag indicating if instructions are currently displayed */
        bool isMenuDisplayed = false; /** Flag indicating if the menu has been displayed */

        /**
         * Displays the choices available in the main menu.
         * This includes the options for starting the game, viewing instructions, and exiting.
         */
        void displayChoice();

        /**
         * Displays the game instructions to help the player understand the rules.
         */
        void displayInstructions();
};

#endif
