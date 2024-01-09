cmake_minimum_required(VERSION 3.24)
project(ProvaFinale)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProvaFinale src/main.cpp include/Player.h include/Human.h include/Pc.h include/Board.h include/BoardBox.h src/Player.cpp include/BoardManager.h src/Board.cpp src/Human.cpp src/Pc.cpp src/BoardBox.cpp include/exceptions.h include/BoardBoxBlank.h include/BoardBoxProperty.h)
