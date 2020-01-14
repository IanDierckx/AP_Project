#include <utility>

//
// Created by student on 12.12.19.
//

#include "../Include/GameLogic/Level.h"
#include "../../SFML/Include/Level.h"


#include <iostream>

namespace GameLogic{
    int Level::getGrid_x() const {
        return grid_x;
    }

    void Level::setGrid_x(int grid_x) {
        Level::grid_x = grid_x;
    }

    int Level::getGrid_y() const {
        return grid_y;
    }

    void Level::setGrid_y(int grid_y) {
        Level::grid_y = grid_y;
    }

    void Level::addRow(vector<pair<bool, shared_ptr<Entity>>> row) {
        grid.emplace_back(row);
    }

    void Level::addEnemyShip(shared_ptr<Ship>ship) {
        enemyShips.emplace_back(ship);
    }

    void Level::addEntityToGrid(shared_ptr<Entity> entity) {
        grid[entity->getY()][entity->getX()].first = true;
        grid[entity->getY()][entity->getX()].second = entity;
    }

    void Level::printLevel() {
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

    void Level::updateGrid() {
        for (int y = 0; y < grid_y; ++y) {
            for (int x = 0; x < grid_x; ++x) {
                if (grid[y][x].first) {
                    grid[y][x].first = false;
                    grid[y][x].second = nullptr;
                }
            }
        }
        for (const auto &enemy:enemyShips) {
            grid[enemy->getY()][enemy->getX()].first = true;
            grid[enemy->getY()][enemy->getX()].second = enemy;
        }

        grid[player->getY()][player->getX()].first = true;
        grid[player->getY()][player->getX()].second = player;
    }

    shared_ptr<Player> Level::getPlayer() const {
        return player;
    }

    void Level::setPlayer(shared_ptr<Player> player) {
        Level::player = std::move(player);
    }

    void Level::update() {
        for (auto &enemyShip : enemyShips) {
            enemyShip->move();
        }
        updateGrid();
        printLevel();
    }

    bool Level::gameOver() {
        if (enemyShips.empty()) {
            return true;
        }
        for (auto &enemyShip : enemyShips) {
            if (std::abs(enemyShip->getMovingY() - 6) < 0.001) {
                return true;
            }
        }
        return false;
    }
}

