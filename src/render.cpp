#include "../include/render.h"
#include "../include/gamestate.h"
#include <thread>
#include <chrono>

Render::Render(SnakeGame &snakeGame) : snakeGame(snakeGame) {}

void Render::render() {
    bool isDisplayedPlaying = false;
    while (gameState != GameState::Exit) {
        if (gameState == GameState::Menu) {
            snakeGame.getMenu()->display();
        } else if (gameState == GameState::Playing) {
            if (!isDisplayedPlaying) {
                snakeGame.getPlaying()->display();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                isDisplayedPlaying = true;
            }
        }
    }
}
