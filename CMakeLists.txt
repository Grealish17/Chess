cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp chess.h queen.cpp game_history.cpp game_descriptor.cpp king.cpp rook.cpp bishop.cpp knight.cpp pawn.cpp)
