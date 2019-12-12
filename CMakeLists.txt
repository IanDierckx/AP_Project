cmake_minimum_required(VERSION 3.12)
project(AP_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Project main.cpp GameLogic/src/Game.cpp GameLogic/Include/GameLogic/Game.h GameLogic/src/Entity.cpp GameLogic/Include/GameLogic/Entity.h GameLogic/src/Stopwatch.cpp GameLogic/Include/GameLogic/Stopwatch.h GameLogic/src/Ship.cpp GameLogic/Include/GameLogic/Ship.h
        GameLogic/src/PlayerShip.cpp GameLogic/Include/GameLogic/PlayerShip.h GameLogic/src/BasicEnemy.cpp GameLogic/Include/GameLogic/BasicEnemy.h GameLogic/src/LevelParser.cpp GameLogic/Include/GameLogic/LevelParser.h GameLogic/Include/lib/json.hpp)