#include "../include/snakeGame.h"
#include <iostream>
#include <string>

void displayHelp() {
    std::cout << "Snake Game Help\n";
    std::cout << "Usage: snakegame [--help]\n\n";
    std::cout << "Options:\n";
    std::cout << "  --help        Show this help message and exit\n";
    std::cout << "\n";
    std::cout << "Gameplay:\n";
    std::cout << "Snake Game Instructions:\n";
    std::cout << "1. Use arrow keys to move the snake.\n";
    std::cout << "2. Eat the food to grow your snake.\n";
    std::cout << "3. Avoid hitting walls or yourself.\n";
    std::cout << "4. The game ends if you hit a wall, the snake's body, or reach the maximum score.\n";
    std::cout << "\n";
    std::cout << "Menu Options:\n";
    std::cout << "1. Start Game - Press '1' to start playing.\n";
    std::cout << "2. Exit Game - Press '2' to exit the game.\n";
    std::cout << "\n";
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            displayHelp();
            return 0;
        }
    }
    SnakeGame snake;
    snake.run();
    return 0;
}
