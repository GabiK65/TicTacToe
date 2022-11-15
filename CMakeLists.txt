cmake_minimum_required(VERSION 3.0)

project(TicTacToe VERSION 0.1.1)

add_executable(TicTacToe ${PROJECT_SOURCE_DIR}/src/TicTacToe.cpp)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)