#include "../include/playing.h"
#include "../include/gamedata.h"
#include <iostream>
#include <ostream>

Playing::Playing(SnakeGame &game) : game(game) {
    initializeMap();
}

void Playing::initializeMap() {
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWitdth; j++) {
            if (j == 0 || j == mapWitdth - 1 || i == 0 || i == mapHeight - 1)
                map[i][j] = GameData::Map::BORDER;
            else
                map[i][j] = GameData::Map::EMPTY_SPACE;
        }
    }
    map[mapHeight / 2][mapWitdth / 2] = GameData::Map::SNAKE;
}



void Playing::display() {
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWitdth; j++) {
            if (j == 0 || j == mapWitdth - 1 || i == 0 || i == mapHeight - 1)
                std::cout << "#";
            else if (map[i][j] == GameData::Map::SNAKE)
                std::cout << "o";
            else if (map[i][j] == GameData::Map::FOOD)
                std::cout << "+";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}
