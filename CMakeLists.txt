cmake_minimum_required(VERSION 3.12)
project(AP_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Project main.cpp Game.cpp Game.h Entity.cpp Entity.h Stopwatch.cpp Stopwatch.h Ship.cpp Ship.h
        PlayerShip.cpp PlayerShip.h BasicEnemy.cpp BasicEnemy.h LevelParser.cpp LevelParser.h json.hpp)