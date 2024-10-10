#include "../include/snakegame.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/render.h"

GameState gameState = GameState::Menu;

void SnakeGame::run() {
    menu = new Menu(*this);
    playing = new Playing(*this);
    render = new Render(*this);
    render->render();
    delete menu;
    delete playing;
}

void SnakeGame::updateMenu() {
}

void SnakeGame::updatePlaying() {
}

void SnakeGame::setCurrentState(GameState state) {
    gameState = state;
}

Menu* SnakeGame::getMenu() {
    return menu;
}

Playing* SnakeGame::getPlaying() {
    return playing;
}