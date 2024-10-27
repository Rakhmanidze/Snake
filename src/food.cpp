#include "../include/food.h"
#include "../include/gameData.h"
#include <ctime>
#include <cstdlib>

Food::Food() : exists(true) {
    srand(static_cast<unsigned int>(time(0)));
    spawn(std::vector<Coordinate>());
}

void Food::spawn(const std::vector<Coordinate>& snakeBody) {
    foodXY = Coordinate(rand() % (GameData::MapDimensions::WIDTH - 2) + 1,
                      rand() % (GameData::MapDimensions::HEIGHT - 2) + 1);

    while (isFoodOnSnake(snakeBody)) {
        foodXY = Coordinate(rand() % (GameData::MapDimensions::WIDTH - 2) + 1 , rand() % (GameData::MapDimensions::HEIGHT - 2) + 1);
    }
}

bool Food::isFoodOnSnake(const std::vector<Coordinate>& snakeBody) const {
    for (const auto& segment : snakeBody)
        if (segment == foodXY)
            return true;
    return false;
}

void Food::remove() {
    exists = false;
}

bool Food::isExist() const {
    return exists;
}
Coordinate Food::getCoordinate() const {
    return foodXY;
}