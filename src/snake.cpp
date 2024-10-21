#include "../include/snake.h"
#include "../include/direction.h"

Snake::Snake() : alive(true), score(0), currentDirection(Direction::RIGHT) {
    createSnake();
}

void Snake::createSnake() {
    snake.push_back(Coordinate(5, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(4, GameData::MapDimensions::HEIGHT / 2));
    snake.push_back(Coordinate(3, GameData::MapDimensions::HEIGHT / 2));
}

int Snake::update() {
    return move();
}

void Snake::setDirection(Direction newDirection) const {
    if (!alive)
        return;

    if ((newDirection == Direction::LEFT && direction == Direction::RIGHT) ||
        (newDirection == Direction::RIGHT && direction == Direction::LEFT) ||
        (newDirection == Direction::UP && direction == Direction::DOWN) ||
        (newDirection == Direction::DOWN && direction == Direction::UP)) {
        return;
        }
    direction = newDirection;
}

int Snake::move() {
    if (!alive)
        return 1;

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

    if (newX < 1 || newX >= GameData::MapDimensions::WIDTH || newY < 1 || newY >= GameData::MapDimensions::HEIGHT) {
        die();
        return 1;
    }
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].x == newX && snake[i].y == newY) {
            die();
            return 1;
        }
    }

    for (int i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    snake[0].x = newX;
    snake[0].y = newY;
    return 0;
}

void Snake::grow() {
    Coordinate tail = snake.back();
    Coordinate newTail = tail;

    if (direction == Direction::UP)
        newTail.y += 1;
    else if (direction == Direction::DOWN)
        newTail.y -= 1;
    else if (direction == Direction::LEFT)
        newTail.x += 1;
    else if (direction == Direction::RIGHT)
        newTail.x -= 1;

    for (size_t i = 0; i < snake.size(); i++) {
        if (snake[i].x == newTail.x && snake[i].y == newTail.y) {
            die();
            return;
        }
    }
    snake.push_back(newTail);
}


void Snake::eat(Food& food) {
    grow();
    score++;
}

void Snake::die() {
    alive = false;
}

std::vector<Coordinate> Snake::getBody() const {
    return snake;
}

int Snake::getScore() const {
    return score;
}

