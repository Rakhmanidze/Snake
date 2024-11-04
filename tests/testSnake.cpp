#include <catch2/catch_test_macros.hpp>
#include "../include/snake.h"

/**
 * Test case to verify the Snake object's initialization, including the initial score,
 * alive status, body size, and positions of the segments. It also checks the eat() method
 * to verify the score increments when the snake eats and the state
 * after calling the die() method to ensure the snake is no longer alive.
 */
TEST_CASE("Snake initialization and death check") {
    Snake snake;
    REQUIRE(snake.getScore() == 0);
    REQUIRE(snake.isAlive() == true);
    REQUIRE(snake.getBody().size() == 3);

    auto body = snake.getBody();
    REQUIRE(body[0].x == 5);
    REQUIRE(body[0].y == GameData::MapDimensions::HEIGHT / 2);
    REQUIRE(body[1].x == 4);
    REQUIRE(body[1].y == GameData::MapDimensions::HEIGHT / 2);
    REQUIRE(body[2].x == 3);
    REQUIRE(body[2].y == GameData::MapDimensions::HEIGHT / 2);

    snake.eat();
    REQUIRE(snake.getScore() == 1);

    snake.die();
    REQUIRE(snake.isAlive() == false);
}

TEST_CASE("Snake movement check") {
    Snake snake;
    snake.setDirection(GameData::Direction::RIGHT);
    snake.update();
    auto body = snake.getBody();
    REQUIRE(body[0].x == 6);
    REQUIRE(body[0].y == GameData::MapDimensions::HEIGHT / 2);

    REQUIRE(body[1].x == 5);
    REQUIRE(body[1].y == GameData::MapDimensions::HEIGHT / 2);

    REQUIRE(body[2].x == 4);
    REQUIRE(body[2].y == GameData::MapDimensions::HEIGHT / 2);
    REQUIRE(snake.isAlive() == true);

    for (int i = 0; i < (GameData::MapDimensions::WIDTH - 6); i++)
        snake.update();

    REQUIRE(snake.isAlive() == false);
}