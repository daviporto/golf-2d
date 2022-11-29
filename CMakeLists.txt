cmake_minimum_required(VERSION 3.22)
project(pds2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(pds2
        Background.cpp
        Background.h
        Ball.cpp
        Ball.h
        Entity.cpp
        Entity.h
        Hole.cpp
        Hole.h
        Launcher.cpp
        Launcher.h
        Level.cpp
        Level.h
        Level1.cpp
        Level1.h
        Origem.cpp
        Screen.cpp
        Screen.h)

target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::TTF SDL2::Image)

