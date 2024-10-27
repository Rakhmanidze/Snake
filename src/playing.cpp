#include "../include/playing.h"
#include "../include/gameData.h"
#include "../include/clearScreen.h"
#include <iostream>
#include <ostream>
#include <chrono>
#include <thread>

Playing::Playing(SnakeGame &game) : snakeGame(game) {
    initializeMap();
}

void Playing::reset() {
    snake = Snake();
    snakeGame.getKeyboardManager()->setLastInputDirection(GameData::Direction::RIGHT);
    initializeMap();
    running = true;
    printFinishMessageOnce = false;
    gameover = false;
}

void Playing::initializeMap() {
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWitdth; j++) {
            if (j == 0 || j == mapWitdth - 1 || i == 0 || i == mapHeight - 1)
                map[i][j] = GameData::MapTileType::WALL;
            else
                map[i][j] = GameData::MapTileType::EMPTY_SPACE;
        }
    }
    spawnMultipleFoods(20);

    map[snake.getBody()[0].y][snake.getBody()[0].x] = GameData::MapTileType::SNAKE;
}

void Playing::spawnMultipleFoods(int count) {
    foods.clear();
    for (int i = 0; i < count; ++i) {
        Food food;

        bool validPosition = false;
        while (!validPosition) {
            food.spawn(snake.getBody());
            validPosition = true;

            for (const auto& existingFood : foods) {
                if (existingFood.getCoordinate() == food.getCoordinate()) {
                    validPosition = false;
                    break;
                }
            }
        }
        foods.push_back(food);
        map[food.getCoordinate().y][food.getCoordinate().x] = GameData::MapTileType::FOOD;
    }
}

void Playing::update() {
    snake.setDirection(snakeGame.getKeyboardManager()->getLastInputDirection());
    removeSnakeFromMap();
    if (snake.update()) {
        running = false;
        gameover = true;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        snakeGame.setCurrentGameState(GameState::Menu);
    }
    updateSnakePosition();
    for (auto food = foods.begin(); food != foods.end(); ) {
        if (snake.getBody()[0].x == food->getCoordinate().x && snake.getBody()[0].y == food->getCoordinate().y) {
            snake.eat();
            food = foods.erase(food);
        } else
            food++;
    }

    if (snake.getScore() >= GameData::Score::MAX_SCORE) {
        running = false;
        gameover = false;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        snakeGame.setCurrentGameState(GameState::Menu);
    }
    if (!running)
        reset();
}

void Playing::updateSnakePosition() {
    for (const auto &part : snake.getBody())
        map[part.y][part.x] = GameData::MapTileType::SNAKE;
}

void Playing::removeSnakeFromMap() {
    for (const auto &part : snake.getBody())
        map[part.y][part.x] = GameData::MapTileType::EMPTY_SPACE;
}

void Playing::printGameFinishedMessage() {
    if (!printFinishMessageOnce) {
        if (gameover) {
            std::cout << "Game Over!\n";
            std::cout << "Redirecting to menu in 5 seconds...\n";
        } else if (!gameover) {
            std::cout << "Congratulations! You've won the game!\n";
            std::cout << "Redirecting to menu in 5 seconds...\n";
        }
        printFinishMessageOnce = true;
    }
}

void Playing::display() {
    if (running) {
        clearScreen();
        displayMap();
        displayScore();
    } else
        printGameFinishedMessage();
}

void Playing::displayMap() {
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWitdth; j++) {
            if (j == 0 || j == mapWitdth - 1 || i == 0 || i == mapHeight - 1)
                std::cout << "#";
            else if (map[i][j] == GameData::MapTileType::SNAKE)
                std::cout << "o";
            else if (map[i][j] == GameData::MapTileType::FOOD)
                std::cout << "+";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

void  Playing::displayScore() const {
    std::cout << "Current Score: " << snake.getScore() << " | Max Score: " << GameData::Score::MAX_SCORE << "\n";
}

Snake Playing::getSnake() {
    return snake;
}

bool Playing::isRunning() {
    return running;
}