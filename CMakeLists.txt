cmake_minimum_required(VERSION 3.29)
project(semak_cpp)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(semak_cpp src/main.cpp
        src/menu.cpp
        include/menu.h
        include/snakegame.h
        src/snakegame.cpp
        include/gamestate.h
        src/playing.cpp
        include/playing.h
        include/gamedata.h
        include/render.h
        src/render.cpp
        src/render.cpp
        include/update.h
        src/update.cpp
        include/snake.h
        src/snake.cpp
        include/coordinate.h
        include/food.h
        src/food.cpp
        include/clearscreen.h
        src/clearscreen.cpp
        include/keyboardlistener.h
        src/keyboardlistener.cpp
)

add_executable(tests_snake
        tests/testsMain.cpp
        tests/testsSnake.cpp
        src/snake.cpp
)

add_executable(tests_playing
        tests/testsMain.cpp
        tests/testsPlaying.cpp
        src/playing.cpp
        src/food.cpp
        src/snake.cpp
        src/clearScreen.cpp
        src/snakeGame.cpp
        src/keyboardListener.cpp
        src/update.cpp
        src/render.cpp
        src/menu.cpp
)

add_executable(test_food
        tests/testsMain.cpp
        tests/testFood.cpp
        src/snake.cpp
        src/food.cpp
        src/playing.cpp
        src/clearScreen.cpp
        src/snakeGame.cpp
        src/keyboardListener.cpp
        src/update.cpp
        src/render.cpp
        src/menu.cpp
)

target_link_libraries(tests_snake PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests_playing PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test_food PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME tests_snake COMMAND tests_snake)
add_test(NAME tests_playing COMMAND tests_playing)
add_test(NAME test_food COMMAND tests_playing)