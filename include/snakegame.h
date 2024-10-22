#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "../include/gamestate.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/update.h"
#include "../include/keyboardmanager.h"

/**
 *  Forward declarations for other classes used within SnakeGame.
 */
class Menu;
class Playing;
class Render;
class Update;
class KeyboardManager;

/**
 * Represents the main game logic and control flow for the Snake game.
 */
class SnakeGame {
    public:
        /**
         * Starts the game loop, managing the flow between different game states.
         */
        void run();

        /**
         * Sets the current game state to the specified state.
         * @param state The new state of the game (Menu, Playing, Exit).
         */
        static void setCurrentState(GameState state);

        /**
         * Retrieves the menu object for the game.
         * @return A pointer to the Menu instance.
         */
        Menu* getMenu() const;

        /**
         * Retrieves the playing object for the game.
         * @return A pointer to the Playing instance.
         */
        Playing* getPlaying() const;

        /**
         * Retrieves the keyboard manager for the game.
         * @return A pointer to the KeyboardManager instance.
         */
        KeyboardManager* getKeyboardManager() const;

    private:
        Menu* menu;                       /** Pointer to the menu object */
        Playing* playing;                 /** Pointer to the playing object */
        Render* render;                   /** Pointer to the render object */
        Update* update;                   /** Pointer to the update object */
        KeyboardManager* keyboardManager; /** Pointer to the keyboard manager object */
};

#endif
