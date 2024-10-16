#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <utility>

class GameData {
    public:
        class MapDimensions {
            public:
                static const int WIDTH = 55;
                static const int HEIGHT = 15;
        };
        class MapTileType {
        public:
            static const int EMPTY_SPACE = 0;
            static const int WALL = 1;
            static const int FOOD = 2;
            static const int SNAKE = 3;
        };
};

#endif
