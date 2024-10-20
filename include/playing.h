#ifndef PLAYING_H
#define PLAYING_H

#include "snake.h"
#include "../include/gamedata.h"
#include "../include/snakegame.h"

class SnakeGame;

class Playing {
    public:
        Playing(SnakeGame& game);
        void display();
        void update();
        void SnakeMovesDisplay();
        Snake getSnake();
        void reset();

    private:
        SnakeGame& snakeGame;
        int mapWitdth = GameData::MapDimensions::WIDTH;
        int mapHeight = GameData::MapDimensions::HEIGHT;
        int map[GameData::MapDimensions::HEIGHT][GameData::MapDimensions::WIDTH];
        Snake snake;
        void initializeMap();
        void updateSnakePosition();
        void removeSnakeFromMap();
    };

#endif
