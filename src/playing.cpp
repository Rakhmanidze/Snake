#include "../include/playing.h"
#include "../include/gamedata.h"
#include "../include/clearscreen.h"
#include <iostream>
#include <ostream>
#include <chrono>
#include <thread>

Playing::Playing(SnakeGame &game) : snakeGame(game) {
    initializeMap();
}

void Playing::reset() {
    snake = Snake();
    direction = Direction::RIGHT;
    snakeGame.getKeyboardManager()->setDirection(Direction::RIGHT);
    initializeMap();
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
    removeSnakeFromMap();
    if (snake.update()) {
        std::cout << "Game Over!\n";
        std::cout << "Redirecting to menu in 5 seconds...\n";

        std::this_thread::sleep_for(std::chrono::seconds(5));
        snakeGame.setCurrentState(GameState::Menu);
    }
    updateSnakePosition();
    for (auto food = foods.begin(); food != foods.end(); ) {
        if (snake.getBody()[0].x == food->getCoordinate().x && snake.getBody()[0].y == food->getCoordinate().y) {
            snake.eat(*food);
            food = foods.erase(food);
        } else
            food++;
    }

    if (snake.getScore() >= GameData::Score::MAX_SCORE) {
        std::cout << "Congratulations! You've won the game!\n";
        std::cout << "Redirecting to menu in 5 seconds...\n";

        std::this_thread::sleep_for(std::chrono::seconds(5));
        snakeGame.setCurrentState(GameState::Menu);
    }
}

void Playing::updateSnakePosition() {
    for (const auto &part : snake.getBody())
        map[part.y][part.x] = GameData::MapTileType::SNAKE;
}

void Playing::removeSnakeFromMap() {
    for (const auto &part : snake.getBody())
        map[part.y][part.x] = GameData::MapTileType::EMPTY_SPACE;
}

void Playing::SnakeMovesDisplay() {
    for (int i = 0; i < mapHeight; i++)
        for (int j = 0; j < mapWitdth; j++)
            if (map[i][j] == GameData::MapTileType::SNAKE)
                std::cout << "o";
}

void Playing::display() {
    clearScreen();
    displayMap();
    displayScore();
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