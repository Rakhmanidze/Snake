#include "../include/snakegame.h"
#include "../include/menu.h"
#include "../include/playing.h"

void SnakeGame::run() {
    currentState = GameState::Menu;
    menu = new Menu(*this);
    playing = new Playing(*this);
    while (currentState != GameState::Exit) {
        if (currentState == GameState::Menu) {
            updateMenu();
        } if (currentState == GameState::Playing) {
            updatePlaying();
            break; //tmp delete later
        } if (currentState == GameState::Exit) {
            break;
        }
    }
    delete menu;
    delete playing;
}

void SnakeGame::updateMenu() {
    menu->displayMenu();
}

void SnakeGame::updatePlaying() {
    playing->displayPlayingScene();
}

void SnakeGame::setCurrentState(GameState state) {
    currentState = state;
}
