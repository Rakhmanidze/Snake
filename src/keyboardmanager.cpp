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
                setDirection(Direction::UP);
            else if (ch == 80)
                setDirection(Direction::DOWN);
            else if (ch == 75)
               setDirection(Direction::LEFT);
            else if (ch == 77)
                setDirection(Direction::RIGHT);
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
            setDirection(Direction::UP);
        else if (ch == KEY_DOWN)
            setDirection(Direction::DOWN);
        else if (ch == KEY_LEFT)
            setDirection(Direction::LEFT);
        else if (ch == KEY_RIGHT)
            setDirection(Direction::RIGHT);
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

void KeyboardManager::setDirection(Direction newDirection) {
    if ((newDirection == Direction::LEFT && direction == Direction::RIGHT) ||
      (newDirection == Direction::RIGHT && direction == Direction::LEFT) ||
      (newDirection == Direction::UP && direction == Direction::DOWN) ||
      (newDirection == Direction::DOWN && direction == Direction::UP)) {
        return;
      }
    direction = newDirection;
}