#include "../include/snake.h"
#include "../include/direction.h"

Direction direction = Direction::RIGHT;

Snake::Snake() : alive(true), length(1), score(0), speed(1) {
    createSnake();
}

void Snake::createSnake() {
    snake.push_back(Coordinate(5, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(4, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(3, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(2, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(1, GameData::MapDimensions::HEIGHT / 2));
}

int Snake::update() {
    return move();
}

int Snake::move() {
    int newX = snake[0].x;
    int newY = snake[0].y;
    if (direction == Direction::RIGHT)
        newX += 1;
    else if (direction == Direction::LEFT)
        newX -= 1;
    else if (direction == Direction::UP)
        newY -= 1;
    else if (direction == Direction::DOWN)
        newY += 1;

    if (newX < 0 || newX >= GameData::MapDimensions::WIDTH || newY < 0 || newY >= GameData::MapDimensions::HEIGHT)
        return 1;

    for (int i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    snake[0].x = newX;
    snake[0].y = newY;
    return 0;
}

void Snake::grow() {

}

void Snake::eat() {

}

void Snake::die() {

}

bool Snake::isAlive() const {

}

int Snake::getLength() const {

}

int Snake::getScore() const {

}

std::vector<Coordinate> Snake::getBody() const {
    return snake;
}
