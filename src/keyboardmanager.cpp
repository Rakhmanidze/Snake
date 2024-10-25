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
    if (gameState ==  GameState::Playing) {
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
    } else if (gameState == GameState::Menu) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == '1') {
                snakeGame.getPlaying()->reset();
                gameState = GameState::Playing;
                snakeGame.getMenu()->setMenuDisplayed(false);
            } else if (ch == '2') {
                snakeGame.getMenu()->setIntructions(true);
                snakeGame.getMenu()->setMenuDisplayed(false);
            } else if (ch == '3')
                gameState = GameState::Exit;
        }
    }

#elif defined(__linux__) || defined(__APPLE__)
    if (gameState == GameState::Playing) {
        int ch = getch();
        if (ch == KEY_UP)
            currentDirection = Direction::UP;
        else if (ch == KEY_DOWN)
            currentDirection = Direction::DOWN;
        else if (ch == KEY_LEFT)
            currentDirection = Direction::LEFT;
        else if (ch == KEY_RIGHT)
            currentDirection = Direction::RIGHT;
    } else if (gameState == GameState::Menu) {
        int ch = getch();
        if (ch == '1') {
            snakeGame.getPlaying()->reset();
            gameState = GameState::Playing;
            snakeGame.getMenu()->setMenuDisplayed(false);
        } else if (ch == '2') {
            snakeGame.getMenu()->setIntructions(true);
            snakeGame.getMenu()->setMenuDisplayed(false);
        } else if (ch == '3') {
            gameState = GameState::Exit;
        }
    }
#endif
}

Direction KeyboardManager::getDirection() {
    return currentDirection;
}

void KeyboardManager::setDirection(Direction newDirection) {
    currentDirection = newDirection;
}