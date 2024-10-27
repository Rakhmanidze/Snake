#include "../include/update.h"
#include "../include/gamestate.h"

Update::Update(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Update::update() const {
    if (snakeGame.getCurrentGameState() == GameState::Playing) {
        snakeGame.getPlaying()->update();
    }
}
