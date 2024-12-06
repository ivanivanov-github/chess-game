cmake_minimum_required(VERSION 3.10)

project(ChessGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ChessGame main.cpp game_engine.cpp player.cpp)

# target_include_directories(ChessGame PRIVATE $(CMAKE_SOURCE_DIR))