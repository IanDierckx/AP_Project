#include "Game.h"

#include <iostream>

void Game::initializeLevel() {
    for (int x = 0; x < grid_y; ++x) {
        vector<pair<bool,Entity*>> row;
        for (int y = 0; y < grid_x; ++y) {
            row.emplace_back(false, nullptr);
        }
        grid.emplace_back(row);
    }
}

void Game::printLevel() {
    for (int x = 0; x < grid_y; ++x) {
        for (int y = 0; y < grid_x; ++y) {
            if (!grid[x][y].first) {
                cout << ".";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}
