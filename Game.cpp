#include "Game.h"
#include "Ship.h"
#include "PlayerShip.h"

#include <iostream>

void Game::initializeLevel() {
    for (int x = 0; x < grid_y; ++x) {
        vector<pair<bool,Entity*>> row;
        for (int y = 0; y < grid_x; ++y) {
            row.emplace_back(false, nullptr);
        }
        grid.emplace_back(row);
    }

    Ship* testship = new Ship(make_pair(1,1),1,1);
    addEntityToGrid(testship);
    PlayerShip* player = new PlayerShip(make_pair(0,0),5,1);
    addEntityToGrid(player);
}

void Game::printLevel() {
    for (int x = 0; x < grid_y; ++x) {
        for (int y = 0; y < grid_x; ++y) {
            auto current_pos = grid[x][y];
            if (!current_pos.first) {
                cout << ".";
            } else if (current_pos.second->getType() == "Ship"){
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
