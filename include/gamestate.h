#ifndef GAMESTATE_H
#define GAMESTATE_H


/**
 * Represents the different states of the game.
 */
enum class GameState {
    Menu, Playing, Exit
};

/**
 * Declare an external variable to hold the current game state.
 */
extern GameState gameState;

#endif
