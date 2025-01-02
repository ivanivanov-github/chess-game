cmake_minimum_required(VERSION 3.10)

project(ChessGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utilities)

file(GLOB SOURCES "*cpp")

add_library(chessEngine STATIC ${SOURCES})

add_executable(chessGame main.cpp)
target_link_libraries(chessGame chessEngine utilities)