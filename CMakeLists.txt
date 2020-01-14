cmake_minimum_required(VERSION 3.12)
project(AP_Project)

set(CMAKE_CXX_STANDARD 14)


add_executable(AP_Project main.cpp GameLogic/src/Game.cpp GameLogic/Include/GameLogic/Game.h GameLogic/src/Entity.cpp GameLogic/Include/GameLogic/Entity.h GameLogic/src/Stopwatch.cpp GameLogic/Include/GameLogic/Stopwatch.h GameLogic/src/Ship.cpp GameLogic/Include/GameLogic/Ship.h
        GameLogic/src/Player.cpp GameLogic/Include/GameLogic/Player.h GameLogic/src/BasicEnemy.cpp GameLogic/Include/GameLogic/BasicEnemy.h GameLogic/src/LevelParser.cpp GameLogic/Include/GameLogic/LevelParser.h GameLogic/Include/lib/json.hpp SFML/src/Game.cpp SFML/Include/Game.h GameLogic/src/Level.cpp GameLogic/Include/GameLogic/Level.h SFML/src/BasicEnemy.cpp SFML/Include/BasicEnemy.h GameLogic/src/Transformation.cpp GameLogic/Include/GameLogic/Transformation.h SFML/src/Level.cpp SFML/Include/Level.h SFML/src/utils.cpp SFML/Include/utils.h GameLogic/src/LogicUtils.cpp GameLogic/Include/GameLogic/LogicUtils.h Controller.cpp Controller.h SFML/Include/Player.cpp SFML/Include/Player.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()