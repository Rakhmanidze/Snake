#ifndef PLAYING_H
#define PLAYING_H

#include "snake.h"
#include "../include/gamedata.h"

class SnakeGame;

class Playing {
    public:
        Playing(SnakeGame& game);
        void display();
        void update();
        void updateMap();
    private:
        SnakeGame& game;
        int mapWitdth = GameData::MapDimensions::WIDTH;
        int mapHeight = GameData::MapDimensions::HEIGHT;
        int map[GameData::MapDimensions::HEIGHT][GameData::MapDimensions::WIDTH];
        Snake snake;
        void initializeMap();
        void updateSnakePosition(const Coordinate &newHead);
    };

#endif
