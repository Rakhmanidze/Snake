#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData {
    public:
        class Map {
            public:
                static const int WIDTH = 40;
                static const int HEIGHT = 40;
                static const int EMPTY_SPACE = 0;
                static const int WALL = 1;
                static const int FOOD = 2;
                static const int SNAKE = 3;
        };
};

#endif
