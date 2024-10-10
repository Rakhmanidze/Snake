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
)
