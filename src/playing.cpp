#include "../include/playing.h"
#include "../include/gamedata.h"
#include <iostream>
#include <ostream>

Playing::Playing(SnakeGame &game) : game(game) {
    initializeMap();
    update();
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
    map[mapHeight / 2][mapWitdth / 2] = GameData::MapTileType::SNAKE;
}

void Playing::update() {
    snake.update();
    updateMap();
    for (const auto &part : snake.getBody()) {
        map[part.y][part.x] = GameData::MapTileType::EMPTY_SPACE;
    }
    Coordinate newHead = snake.getBody()[0];

    updateSnakePosition(newHead);
}

void Playing::updateMap() {

}

void Playing::updateSnakePosition(const Coordinate &newHead) {
    snake.getBody()[0] = newHead;
    map[newHead.y][newHead.x] = GameData::MapTileType::SNAKE;

    // If the snake has grown, handle the growth logic
    // For example, if the snake has eaten food,  add a new body segment here.
}

void Playing::display() {
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