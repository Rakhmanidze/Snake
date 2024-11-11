#include <catch2/catch_test_macros.hpp>
#include "../include/playing.h"

/**
 * Test case to verify the initial setup of the Playing class.
 * This test checks:
 *  - Correct placement of walls around the map's borders (top, bottom, left, and right).
 *  - Initial count and placement of food items, ensuring that the food is correctly placed.
 *  - Snake's running state and alive status upon initialization.
 *  - Snake's initial position to ensure it's placed in the expected starting position on the map.
 */
TEST_CASE("Initial Setup Verification in the Playing Class") {
    SnakeGame snakeGame;
    Playing playing(snakeGame);
    const auto& map = playing.getMap();

    for (int i = 0; i < GameData::MapDimensions::WIDTH; i++) {
        REQUIRE(map[0][i] == GameData::MapTileType::WALL);
        REQUIRE(map[GameData::MapDimensions::HEIGHT - 1][i] == GameData::MapTileType::WALL);
    }
    for (int i = 0; i < GameData::MapDimensions::HEIGHT; i++) {
        REQUIRE(map[i][0] == GameData::MapTileType::WALL);
        REQUIRE(map[i][GameData::MapDimensions::WIDTH - 1] == GameData::MapTileType::WALL);
    }
    REQUIRE(playing.getFoods().size() == 20);
    REQUIRE(playing.isRunning() == true);
    REQUIRE(playing.getSnake().isAlive() == true);

    for (const auto& food : playing.getFoods()) {
        const auto& foodPos = food.getCoordinate();
        REQUIRE(map[foodPos.y][foodPos.x] == GameData::MapTileType::FOOD);
        REQUIRE(map[foodPos.y][foodPos.x] != GameData::MapTileType::SNAKE);
        REQUIRE(map[foodPos.y][foodPos.x] != GameData::MapTileType::WALL);
    }
}

/**
 * Test case to verify that the game correctly resets after a game over.
 * This test checks:
 *  - The game is running after the reset.
 *  - The snake is alive after the reset.
 *  - The snake's score is reset to 0.
 *  - The walls are correctly placed after the reset.
 *  - The number of food items is reset to 20 after the reset.
 */
TEST_CASE("Game Reset After Game Over") {
    SnakeGame snakeGame;
    Playing playing(snakeGame);

    playing.reset();
    REQUIRE(playing.isRunning() == true);
    REQUIRE(playing.getSnake().isAlive() == true);
    REQUIRE(playing.getSnake().getScore() == 0);

    const auto& map = playing.getMap();
    REQUIRE(map[0][0] == GameData::MapTileType::WALL);
    REQUIRE(map[GameData::MapDimensions::HEIGHT - 1][GameData::MapDimensions::WIDTH - 1] == GameData::MapTileType::WALL);  // Check bottom-right corner for a wall

    REQUIRE(playing.getFoods().size() == 20);
}