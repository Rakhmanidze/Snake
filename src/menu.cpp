#include "../include/menu.h"
#include "../include/snakeGame.h"
#include "../include/clearScreen.h"
#include <iostream>
#include <ostream>

Menu::Menu(SnakeGame &game) : snakeGame(game) {}

void Menu::display() {
    if (!isMenuDisplayed) {
        clearScreen();
        displayChoice();
        displayInstructions();
        isMenuDisplayed = true;
    }
}

void Menu::displayChoice() {
    std::cout << "Snake game Menu:\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option (1-3):\n";
}

void Menu::displayInstructions() {
    if (isInstructionsDisplayed) {
        std::cout << "Snake Game Instructions:\n";
        std::cout << "1. Use arrow keys to move the snake.\n";
        std::cout << "2. Eat the food to grow your snake.\n";
        std::cout << "3. Avoid hitting walls or yourself.\n";
        std::cout << "4. The game ends if you hit a wall, the snake's body, or reach the maximum score.\n";
        setIntructions(false);
    }
}

void Menu::setIntructions(bool value) {
    isInstructionsDisplayed = value;
}

void Menu::setMenuDisplayed(bool value) {
    isMenuDisplayed = value;
}