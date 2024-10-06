#include "../include/snakegame.h"
#include "../include/menu.h"

void SnakeGame::run() {
    currentState = GameState::Menu;
    menu = new Menu(*this);
    while (currentState != GameState::Exit) {
        if (currentState == GameState::Menu) {
            updateMenu();
            break;
        } if (currentState == GameState::Playing) {
            break;
        } if (currentState == GameState::Exit) {
            break;
        }
    }
    delete menu;
}

void SnakeGame::updateMenu() {
    menu->displayMenu();
}

void SnakeGame::setCurrentState(GameState state) {
    currentState = state;
}
