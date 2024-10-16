#include "../include/snakegame.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/render.h"
#include "../include/update.h"
#include <thread>
#include <chrono>

GameState gameState = GameState::Menu;

void SnakeGame::run() {
    menu = new Menu(*this);
    playing = new Playing(*this);
    render = new Render(*this);
    update = new Update(*this);
    render->render();
    update->update();
    delete menu;
    delete playing;
    delete render;
    delete update;
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