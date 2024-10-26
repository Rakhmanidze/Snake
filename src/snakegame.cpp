#include "../include/snakegame.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/render.h"
#include "../include/update.h"
#include "../include/direction.h"
#include <thread>

GameState gameState = GameState::Menu;
Direction direction = Direction::RIGHT;

void SnakeGame::updateLoop() {
    while (gameState != GameState::Exit && getPlaying()->isRunning()) {
        update->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void SnakeGame::renderLoop() {
     while (gameState != GameState::Exit) {
         render->render();
         std::this_thread::sleep_for(std::chrono::milliseconds(150));
     }
}

void SnakeGame::inputLoop() {
    while (gameState != GameState::Exit) {
        getKeyboardManager()->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void SnakeGame::run() {
    menu = new Menu(*this);
    playing = new Playing(*this);
    render = new Render(*this);
    update = new Update(*this);
    keyboardManager = new KeyboardManager(*this);

    std::thread updateThread(updateLoop, this);
    std::thread renderThread(renderLoop, this);
    std::thread inputThread(inputLoop, this);

    updateThread.join();
    renderThread.join();
    inputThread.join();

    delete menu;
    delete playing;
    delete render;
    delete update;
    delete keyboardManager;
}

void SnakeGame::setCurrentState(GameState state) {
    gameState = state;
}

Menu* SnakeGame::getMenu() const {
    return menu;
}

Playing* SnakeGame::getPlaying() const {
    return playing;
}

KeyboardManager* SnakeGame::getKeyboardManager() const {
    return keyboardManager;
}