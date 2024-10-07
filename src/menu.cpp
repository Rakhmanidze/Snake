#include "../include/menu.h"
#include "../include/gamestate.h"
#include "../include/snakegame.h"
#include <iostream>
#include <ostream>
#include <sstream>

Menu::Menu(SnakeGame &game) : game(game) {}

int Menu::getValidatedInput(const std::string& text, int min, int max) {
    std::string input;
    int choice;

    while (true) {
        std::cout << text;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= min && choice <= max)
            break;
        std::cout << "Invalid input. Please enter a whole number between " << min << " and " << max << ".\n";
    }
    return choice;
}

void Menu::displayMenu() {
    int choice;
    while (true) {
        std::cout << "Snake game Menu:\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Instructions\n";
        std::cout << "3. Exit\n";
        choice = getValidatedInput("Choose an option (1-3):", 1, 3);
        if (choice == 1) {
            game.setCurrentState(GameState::Playing);
            // std::cout << "Starting the game...\n";
            break;
        } if (choice == 2) {
            displayInstructions();
        } else if (choice == 3) {
            std::cout << "Exiting the game...\n";
            return;
        }
    }
}

void Menu::displayInstructions() const {
    std::cout << "Snake Game Instructions:\n";
    std::cout << "1. Use arrow keys to move the snake.\n";
    std::cout << "2. Eat the food to grow your snake.\n";
    std::cout << "3. Avoid hitting walls or yourself.\n";
    std::cout << "4. The game ends if you hit a wall or the snake's body.\n";
}