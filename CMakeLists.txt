cmake_minimum_required(VERSION 3.24)
project(ProvaFinale)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProvaFinale src/main.cpp include/Player.h include/Human.h include/Pc.h include/Board.h include/BoardBox.h include/BoardBoxEco.h include/BoardBoxStd.h include/BoardBoxLux.h include/BoardBoxStart.h)
