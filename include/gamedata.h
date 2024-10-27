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
                static constexpr int WIDTH = 55;
                static constexpr int HEIGHT = 25;
        };

        /**
         * Class that defines different types of tiles on the game map.
         */
        class MapTileType {
            public:
                static constexpr int EMPTY_SPACE = 0;
                static constexpr int WALL = 1;
                static constexpr int FOOD = 2;
                static constexpr int SNAKE = 3;
        };

        /**
         * Class that holds scoring constants for the game.
         */
        class Score {
            public:
                static constexpr int MAX_SCORE = 5;
        };

        /**
         * Class that snake's direction constants.
         */
        class Direction {
        public:
            static constexpr int RIGHT = 0;
            static constexpr int LEFT = 1;
            static constexpr int DOWN = 2;
            static constexpr int UP = 3;
        };
};

#endif
