#include "../include/instructions.h"
#include <iostream>

void Instructions::show() const {
    std::cout << "Snake Game Instructions:\n";
    std::cout << "1. Use arrow keys to move the snake.\n";
    std::cout << "2. Eat the food to grow your snake.\n";
    std::cout << "3. Avoid hitting walls or yourself.\n";
    std::cout << "4. The game ends if you hit a wall or the snake's body.\n";
}