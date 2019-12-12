#include <utility>

#include "../Include/GameLogic/Game.h"
#include "../Include/GameLogic/Ship.h"
#include "../Include/GameLogic/PlayerShip.h"
#include "../Include/GameLogic/BasicEnemy.h"
#include "../../SFML/Include/Game.h"


#include <iostream>

namespace GameLogic {
    void Game::run() {
        bool gameOver = false;
        while (!gameOver) {
            Stopwatch *watch = Stopwatch::getInstance();
            if (watch->getTimePassed() == 1)  {
                for (int i = 0; i < currentLevel.getEnemyShips().size(); ++i) {
                    currentLevel.getEnemyShips()[i]->move();
                    if (currentLevel.getEnemyShips()[i]->getY() == 6) {
                        gameOver = true;
                        break;
                    }
                }
                currentLevel.updateGrid();
                cout << string( 5, '\n' );
                currentLevel.printLevel();
                watch->reset();
            }
        }
    }


    void Game::initializeLevel(string levelFile) {
        LevelParser parser = LevelParser(std::move(levelFile));

        currentLevel = parser.parseJson();

        currentLevel.printLevel();
    }
}

