#ifndef PLAYING_H
#define PLAYING_H

#include "../include/gamedata.h"

class SnakeGame;

class Playing {
    public:
        Playing(SnakeGame& game);
        void displayPlayingScene();
        void displayTheBorder();
    private:
        SnakeGame& game;
        int mapWitdth = GameData::Map::WIDTH;
        int mapHeigth = GameData::Map::HEIGHT;
        int map[GameData::Map::HEIGHT][GameData::Map::WIDTH];
        void initializeMap();
    };

#endif
