#include "../include/playing.h"
#include "../include/gamedata.h"
#include <iostream>
#include <ostream>

Playing::Playing(SnakeGame &game) : game(game) {
    initializeMap();
}

// void Playing::initializeMap() {
//     for (int i = 0; i < mapHeigth; i++) {
//         for (int j = 0; j < mapWitdth; i++) {
//             if (j == 0 || j == mapWitdth - 1)
//                 map[i][j] = GameData::Map::WALL;
//             else
//                 map[i][j] = GameData::Map::EMPTY_SPACE;
//         }
//     }
// }

void Playing::displayPlayingScene() {
    displayTheBorder();
}

void Playing::displayTheBorder() {
    for (int i = 0; i < mapWitdth; i++) {
        std::cout << "#";
    }
    std::cout << "\n";
    for (int i = 0; i < mapWitdth; i++) {
        std::cout << "#";
    }
}
