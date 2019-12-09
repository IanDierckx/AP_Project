#include <utility>

#include "Game.h"
#include "Ship.h"
#include "PlayerShip.h"
#include "BasicEnemy.h"

#include <iostream>


void Game::run() {
    bool gameOver = false;
    int temp = 1;
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
            temp++;
        }
    }
}


void Game::initializeLevel(string levelFile) {
    LevelParser parser = LevelParser(std::move(levelFile));

    currentLevel = parser.parseJson();

    currentLevel.printLevel();
}
