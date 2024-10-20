#include "../include/snake.h"
#include "../include/direction.h"

Direction direction = Direction::RIGHT;

Snake::Snake() : alive(true), length(1), score(0), speed(1) {
    // tmp
    snake.push_back(Coordinate(1, GameData::MapDimensions::HEIGHT / 2));
}

void Snake::update() {
    move();
}

void Snake::move() {

    int newX = snake[0].x;
    int newY = snake[0].y;
    if (direction == Direction::RIGHT) {
        newX += 1;
    }
    else if (direction == Direction::LEFT) {
        newX -= 1;
    }
    else if (direction == Direction::UP) {
        newY -= 1;
    }
    else if (direction == Direction::DOWN) {
        newY += 1;
    }

    if (newX >= 0 && newX < GameData::MapDimensions::WIDTH && newY >= 0 && newY < GameData::MapDimensions::HEIGHT) {
        snake[0].x = newX;
        snake[0].y = newY;

        //tmp: change later so i will set in loop lastXY= last-1XY; last-1XY=last-2XY; and then head to those coord
    } else {
        // Handle the case where the snake hits the wall or itself
    }
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
