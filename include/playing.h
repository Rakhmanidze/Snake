#ifndef PLAYING_H
#define PLAYING_H

#include "../include/gamedata.h"

class SnakeGame;

class Playing {
    public:
        Playing(SnakeGame& game);
        void display();
        void update();
    private:
        SnakeGame& game;
        int mapWitdth = GameData::MapDimensions::WIDTH;
        int mapHeight = GameData::MapDimensions::HEIGHT;
        int map[GameData::MapDimensions::HEIGHT][GameData::MapDimensions::WIDTH];
        void initializeMap();
    };

#endif
