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
        tests/testSnake.cpp
        tests/testsMain.cpp
)

add_executable(semak_tests
        tests/testSnake.cpp
        src/snake.cpp
)
target_link_libraries(semak_tests PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME semak_tests COMMAND semak_tests)


