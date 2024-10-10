#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState {
    Menu, Playing, Exit
};
extern GameState gameState; //must be defined in one .cpp, and use it anywhere by including the header

#endif
