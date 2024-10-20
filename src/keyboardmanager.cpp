#include "../include/keyboardmanager.h"
#ifdef _WIN32
#include <conio.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <ncurses.h> // For Linux/Unix and macOS
#endif

KeyboardManager::KeyboardManager(SnakeGame &game) :  snakeGame(game) {
#if defined(__linux__) || defined(__APPLE__)
    // Initialize ncurses for Linux/Unix
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
#endif
}

void KeyboardManager::update() {
#ifdef _WIN32
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 72)
            currentDirection = Direction::UP;
        else if (ch == 80)
            currentDirection = Direction::DOWN;
        else if (ch == 75)
            currentDirection = Direction::LEFT;
        else if (ch == 77)
            currentDirection = Direction::RIGHT;
    }
#elif defined(__linux__) || defined(__APPLE__)
    int ch = getch(); // For Linux/Unix
    if (ch == KEY_UP)
        currentDirection = Direction::UP;
    else if (ch == KEY_DOWN)
        currentDirection = Direction::DOWN;
    else if (ch == KEY_LEFT)
        currentDirection = Direction::LEFT;
    else if (ch == KEY_RIGHT)
        currentDirection = Direction::RIGHT;
#endif
}

Direction KeyboardManager::getDirection() {
    return currentDirection;
}

void KeyboardManager::setDirection(Direction newDirection) {
    currentDirection = newDirection;
}