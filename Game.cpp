#include "Game.h"
#include "Ship.h"
#include "PlayerShip.h"
#include "BasicEnemy.h"

#include <iostream>

void Game::initializeLevel() {
    for (int x = 0; x < grid_y; ++x) {
        vector<pair<bool,Entity*>> row;
        for (int y = 0; y < grid_x; ++y) {
            row.emplace_back(false, nullptr);
        }
        grid.emplace_back(row);
    }

    BasicEnemy* testship = new BasicEnemy(make_pair(1,1));
    addEntityToGrid(testship);
    enemyShips.emplace_back(testship);
    PlayerShip* player = new PlayerShip(make_pair(0,0),5,1);
    addEntityToGrid(player);
}

void Game::printLevel() {
    for (int x = 0; x < grid_y; ++x) {
        for (int y = 0; y < grid_x; ++y) {
            auto current_pos = grid[x][y];
            if (!current_pos.first) {
                cout << ".";
            } else if (current_pos.second->getType() == "BasicEnemy"){
                cout << "X";
            } else if (current_pos.second->getType() == "Player") {
                cout << "A";
            }
        }
        cout << endl;
    }
}

void Game::addEntityToGrid(Entity *entity) {
    grid[entity->getX()][entity->getY()].first = true;
    grid[entity->getX()][entity->getY()].second = entity;
}

void Game::run() {
    bool gameOver = false;
    int temp = 1;
    while (!gameOver) {
        Stopwatch *watch = Stopwatch::getInstance();
        if (watch->getTimePassed() == 1)  {
            for (int i = 0; i < enemyShips.size(); ++i) {
                enemyShips[i]->move(grid);
                if (enemyShips[i]->getY() == 6) {
                    gameOver = true;
                    break;
                }
            }
            cout << string( 5, '\n' );
            printLevel();
            watch->reset();
            temp++;
        }
    }
}

void Game::moveEntity(Entity *entity) {
    grid[entity->getY()][entity->getX()].first = false;
    grid[entity->getY()][entity->getX()].second = nullptr;
    if ((entity->getX() == 0 and entity->getSpeed() < 0) or (entity->getX() == 8 and entity->getSpeed() > 0)) {
        entity->setY(entity->getY()+1);
        entity->setSpeed(-entity->getSpeed());
    } else {
        entity->setX(entity->getX()+entity->getSpeed());
    }
    grid[entity->getY()][entity->getX()].first = true;
    grid[entity->getY()][entity->getX()].second = entity;
}
