#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData {
    public:
        class Map {
            public:
                static const int WIDTH = 55;
                static const int HEIGHT = 15;
                static const int EMPTY_SPACE = 0;
                static const int BORDER = 1;
                static const int FOOD = 2;
                static const int SNAKE = 3;
        };
        class Direction {
        public:
            static const int RIGHT = 0;
            static const int LEFT = 1;
            static const int UP= 2;
            static const int DOWN = 4;
        };
};

#endif
