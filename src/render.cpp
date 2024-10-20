#include "../include/render.h"
#include "../include/gamestate.h"
#include <thread>
#include <chrono>
#include <iostream>

Render::Render(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Render::render() {
    if (gameState == GameState::Menu)
        snakeGame.getMenu()->display();
    else if (gameState == GameState::Playing)
        snakeGame.getPlaying()->display();
}