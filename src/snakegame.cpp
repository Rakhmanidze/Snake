#include "../include/snakegame.h"
#include "../include/menu.h"
#include "../include/playing.h"
#include "../include/render.h"
#include "../include/update.h"
#include "../include/direction.h"
#include <thread>
#include <chrono>

GameState gameState = GameState::Menu;
Direction direction = Direction::RIGHT;

const int TARGET_FPS = 7; // Target frames per second
const int FRAME_TIME = 1000 / TARGET_FPS; // Time per frame in milliseconds

void SnakeGame::run() {
    menu = new Menu(*this);
    playing = new Playing(*this);
    render = new Render(*this);
    update = new Update(*this);
    keyboardManager = new KeyboardManager(*this);
    while (gameState != GameState::Exit) {
        auto frameStart = std::chrono::high_resolution_clock::now();

        update->update();
        playing->getSnake().setDirection(keyboardManager->getDirection());
        render->render();

        auto frameEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> frameDuration = frameEnd - frameStart;
        int sleepTime = FRAME_TIME - static_cast<int>(frameDuration.count());

        if (sleepTime > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }
    delete menu;
    delete playing;
    delete render;
    delete update;
    delete keyboardManager;
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

KeyboardManager* SnakeGame::getKeyboardManager() {
    return keyboardManager;
}