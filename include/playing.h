#ifndef PLAYING_H
#define PLAYING_H

#include "food.h"
#include "snake.h"
#include "../include/gameData.h"
#include "../include/snakeGame.h"

/**
 *  Forward declaration of the SnakeGame class.
 */
class SnakeGame;

/**
 * Manages the state of the game while it is being played, including displaying the game state,
 * updating the game logic, and handling the snake's movements and food spawning.
 */
class Playing {
    public:
        /**
         * Constructor to initialize the Playing state with a reference to the SnakeGame.
         * @param game Reference to the SnakeGame instance.
         */
        Playing(SnakeGame& game);

        /**
         * Displays the current game state to the user, including the map and score.
         */
        void display();

        /**
         * Updates the game state, including snake movement, food consumption, and checking for game-over conditions.
         */
        void update();

        /**
         * Retrieves the current snake object.
         * @return The current Snake object.
         */
        Snake getSnake();

        /**
         * Resets the game state to the initial conditions.
         */
        void reset();

        /**
         * Checks if the game is currently running.
         * @return True if the game is running, false otherwise.
         */
        bool isRunning();

    private:
        SnakeGame& snakeGame; /** Reference to the SnakeGame instance for managing game state. */
        int mapWitdth = GameData::MapDimensions::WIDTH;
        int mapHeight = GameData::MapDimensions::HEIGHT;
        int map[GameData::MapDimensions::HEIGHT][GameData::MapDimensions::WIDTH]; /** 2D array representing the game map. */
        Snake snake; /** The current snake object in the game. */
        std::vector<Food> foods; /** List of food items currently on the map. */
        bool running = true; /** Indicates if the game is currently running. */
        bool printFinishMessageOnce = false; /** Flag to ensure the game-over message is printed only once. */
        bool gameover = false; /** Indicates whether the game is over. */

        /**
         * Spawns a specified number of food items on the map, ensuring they do not overlap with the snake's body.
         * @param count The number of food items to spawn.
         */
        void spawnMultipleFoods(int count);

        /**
         * Initializes the game map with walls and empty spaces, and places the snake and food items.
         */
        void initializeMap();

        /**
         * Updates the position of the snake on the map.
         */
        void updateSnakePosition();

        /**
         * Removes the snake's current position from the map.
         */
        void removeSnakeFromMap();

        /**
         * Displays the current state of the map, including walls, food, and snake.
         */
        void displayMap();

        /**
         * Displays the current score of the player.
         */
        void displayScore() const;

        /**
         * Prints a message indicating the game has finished.
         * This message is displayed when the game ends, based on the game-over conditions.
         */
        void printGameFinishedMessage();
};

#endif
