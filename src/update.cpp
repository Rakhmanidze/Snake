#include "../include/update.h"
#include "../include/gamestate.h"
#include <chrono>
#include <thread>

Update::Update(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Update::update() {
    while (gameState != GameState::Exit) {
        if (gameState == GameState::Playing) {
            snakeGame.getPlaying()->update();
            // std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}
