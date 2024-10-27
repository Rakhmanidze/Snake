#include "../include/render.h"
#include "../include/gamestate.h"

Render::Render(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Render::render() const {
    if (snakeGame.getCurrentGameState() == GameState::Menu)
        snakeGame.getMenu()->display();
    else if (snakeGame.getCurrentGameState() == GameState::Playing)
        snakeGame.getPlaying()->display();
}
