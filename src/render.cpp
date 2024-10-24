#include "../include/render.h"
#include "../include/gamestate.h"

Render::Render(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Render::render() const {
    if (gameState == GameState::Menu)
        snakeGame.getMenu()->display();
    else if (gameState == GameState::Playing)
        snakeGame.getPlaying()->display();
}
