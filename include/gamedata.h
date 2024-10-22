#ifndef GAMEDATA_H
#define GAMEDATA_H

/**
 * Class that holds constant values related to game data.
 */
class GameData {
    public:
        /**
         * Class that defines the dimensions of the game map.
         */
        class MapDimensions {
            public:
                static const int WIDTH = 55;
                static const int HEIGHT = 25;
        };

        /**
         * Class that defines different types of tiles on the game map.
         */
        class MapTileType {
            public:
                static const int EMPTY_SPACE = 0;
                static const int WALL = 1;
                static const int FOOD = 2;
                static const int SNAKE = 3;
        };

        /**
         * Class that holds scoring constants for the game.
         */
        class Score {
            public:
                static const int MAX_SCORE = 7;
        };
};

#endif
