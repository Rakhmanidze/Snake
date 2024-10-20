#include "../include/update.h"
#include "../include/gamestate.h"
#include <chrono>
#include <thread>

Update::Update(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Update::update() {
    if (gameState == GameState::Playing)
        snakeGame.getPlaying()->update();
}
