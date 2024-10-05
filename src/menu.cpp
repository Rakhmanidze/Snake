#include "../include/menu.h"
#include "../include/instructions.h"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>

int getValidatedInput(const std::string& text, int min, int max) {
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

void Menu::display() {
    int choice;
    Instructions instructions;
    while (true) {
        std::cout << "Snake game Menu:\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Instructions\n";
        std::cout << "3. Exit\n";
        choice = getValidatedInput("Choose an option (1-3): ", 1, 3);
        if (choice == 1) {
            system("cls");
        } else if (choice == 2) {
            instructions.show();
        } else if (choice == 3) {
            std::cout << "Exiting the game...\n";
            return;
        }
    }
}