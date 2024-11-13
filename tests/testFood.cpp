#include <catch2/catch_test_macros.hpp>
#include "../include/playing.h"

/**
 * Test case to verify the functionality of the Food class.
 * This test checks:
 *  - The initial spawn of food to ensure it is placed within the map boundaries.
 *  - The food is not placed on the snake’s body.
 *  - The proper behavior of food removal and existence tracking.
 */
TEST_CASE("Food Class Functionality") {
    SnakeGame snakeGame;
    Playing playing(snakeGame);

    std::vector<Coordinate> snakeBody = {
        Coordinate(5, 5), Coordinate(5, 6), Coordinate(5, 7)  // Example snake body
    };
    Food food;
    food.spawn(snakeBody);

    Coordinate foodPos = food.getCoordinate();
    REQUIRE(foodPos.x >= 1);
    REQUIRE(foodPos.x < GameData::MapDimensions::WIDTH - 1);
    REQUIRE(foodPos.y >= 1);
    REQUIRE(foodPos.y < GameData::MapDimensions::HEIGHT - 1);

    REQUIRE_FALSE(std::find(snakeBody.begin(), snakeBody.end(), foodPos) != snakeBody.end());

    food.remove();
    REQUIRE(food.isExist() == false);
}