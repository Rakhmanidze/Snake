cmake_minimum_required(VERSION 3.29)
project(semak_cpp)

set(CMAKE_CXX_STANDARD 20)

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
        include/direction.h
        include/clearscreen.h
        src/clearscreen.cpp
        include/keyboardmanager.h
        src/keyboardmanager.cpp
)
