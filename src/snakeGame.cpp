#include "../include/snakeGame.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/render.h"
#include "../include/update.h"
#include <thread>

void SnakeGame::updateLoop() {
    while (currentGameState != GameState::Exit && getPlaying()->isRunning()) {
        update->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void SnakeGame::renderLoop() {
     while (currentGameState != GameState::Exit) {
         render->render();
         std::this_thread::sleep_for(std::chrono::milliseconds(150));
     }
}

void SnakeGame::inputLoop() {
    while (currentGameState != GameState::Exit) {
        getKeyboardManager()->handleInput();
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

void SnakeGame::setCurrentGameState(GameState newGameState) {
    currentGameState = newGameState;
}

GameState SnakeGame::getCurrentGameState() const {
    return currentGameState;
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