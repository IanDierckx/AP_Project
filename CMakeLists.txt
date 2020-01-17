cmake_minimum_required(VERSION 3.12)
project(AP_Project)

set(CMAKE_CXX_STANDARD 14)


add_executable(AP_Project main.cpp GameLogic/src/Entity.cpp GameLogic/Include/GameLogic/Entity.h GameLogic/src/Stopwatch.cpp GameLogic/Include/GameLogic/Stopwatch.h GameLogic/src/Ship.cpp GameLogic/Include/GameLogic/Ship.h
        GameLogic/src/Player.cpp GameLogic/Include/GameLogic/Player.h GameLogic/src/BasicEnemy.cpp GameLogic/Include/GameLogic/BasicEnemy.h SFML/src/LevelParser.cpp SFML/Include/LevelParser.h GameLogic/Include/lib/json.hpp SFML/src/Game.cpp SFML/Include/Game.h GameLogic/src/Level.cpp GameLogic/Include/GameLogic/Level.h SFML/src/BasicEnemy.cpp SFML/Include/BasicEnemy.h GameLogic/src/Transformation.cpp GameLogic/Include/GameLogic/Transformation.h SFML/src/Level.cpp SFML/Include/Level.h GameLogic/src/LogicUtils.cpp GameLogic/Include/GameLogic/LogicUtils.h Controller.cpp Controller.h SFML/src/Player.cpp SFML/Include/Player.h GameLogic/src/Bullet.cpp GameLogic/Include/GameLogic/Bullet.h GameLogic/src/BasicEnemyBullet.cpp GameLogic/Include/GameLogic/BasicEnemyBullet.h SFML/src/BasicEnemyBullet.cpp SFML/Include/BasicEnemyBullet.h GameLogic/src/EnergyCannon.cpp GameLogic/Include/GameLogic/EnergyCannon.h SFML/src/EnergyCannon.cpp SFML/Include/EnergyCannon.h GameLogic/src/EnergyBullet.cpp GameLogic/Include/GameLogic/EnergyBullet.h SFML/src/EnergyBullet.cpp SFML/Include/EnergyBullet.h GameLogic/src/DoubleShotEnemy.cpp GameLogic/Include/GameLogic/DoubleShotEnemy.h SFML/src/DoubleShotEnemy.cpp SFML/Include/DoubleShotEnemy.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()