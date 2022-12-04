cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(lab4 main.cpp chess.h queen.cpp game_history.cpp game_descriptor.cpp king.cpp rook.cpp bishop.cpp knight.cpp pawn.cpp piece_texture.cpp)

target_link_libraries(lab4 sfml-graphics)