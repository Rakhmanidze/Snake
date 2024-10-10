#include "../include/update.h"
#include "../include/gamestate.h"

Update::Update(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Update::update() {
    while (gameState != GameState::Exit) {
        if (gameState == GameState::Playing) {
            snakeGame.getPlaying()->update();
        }
    }
}
