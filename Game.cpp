#include "Game.h"
#include "Ship.h"

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
    grid[testship->getX()][testship->getY()].first = true;
    grid[testship->getX()][testship->getY()].second = testship;
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
