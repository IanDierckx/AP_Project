#include <utility>

#include "../Include/GameLogic/Level.h"
#include "../../SFML/Include/Level.h"


#include <iostream>

namespace GameLogic{

    /** Getter for the max x value of the grid set by the grid_x value of the class.
     *
     * @return Integer that is the max x value of the grid
     */
    int Level::getGrid_x() const {
        return grid_x;
    }

    /** Setter for the max x value of the grid set by the grid_x value of the class.
     *
     * @param grid_x The integer value to set the max x value of the grid to.
     */
    void Level::setGrid_x(int grid_x) {
        Level::grid_x = grid_x;
    }

    /** Getter for the max y value of the grid set by the grid_y value of the class.
     *
     * @return Integer that is the max y value of the grid
     */
    int Level::getGrid_y() const {
        return grid_y;
    }

    /** Setter for the max y value of the grid set by the grid_y value of the class.
     *
     * @param grid_y The integer value to set the max y value of the grid to.
     */
    void Level::setGrid_y(int grid_y) {
        Level::grid_y = grid_y;
    }

    /** Adds a new row to the grid.
     * Function adds a new row to the grid, mostly used to add a empty row when setting up the grid
     * @param row Vector that represents the row that gets added to the grid
     */
    void Level::addRow(vector<pair<bool, shared_ptr<Entity>>> row) {
        grid.emplace_back(row);
    }

    /** Adds a new enemy ship to the level.
     * Function to add a new Ship entity to the vector of enemy ships
     * @param ship shared pointer to the new enemy ship to add
     */
    void Level::addEnemyShip(shared_ptr<BasicEnemy>enemy) {
        enemyShips.emplace_back(enemy);
    }

    /** Adds a new entity to the grid.
     * Adds a new entity to the grid. Position in the grid is determined by the position value of the entity
     * @param entity Shared pointer to the entity that needs to be added
     */
    void Level::addEntityToGrid(shared_ptr<Entity> entity) {
        grid[entity->getY()][entity->getX()].first = true;
        grid[entity->getY()][entity->getX()].second = entity;
    }

    /** Updates the grid to accurately represent the current state of the game.
     * Function updates the state of the grid so all entity are in the correct position of the grid
     * according to their position value
     */
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

    /** Function to get the shared pointer to the player.
     * Returns the shared pointer to the player entity
     * @return The shared pointer to the player entity
     */
    shared_ptr<Player> Level::getPlayer() const {
        return player;
    }

    /** Sets the player to the shared pointer of the player entity.
     * Set the player, used only when parsing the level
     * @param player The shared pointer to the p[ayer
     */
    void Level::setPlayer(shared_ptr<Player> player) {
        Level::player = std::move(player);
    }

    /** Updates the level.
     * Function updates the level by moving all enemies to their next position by calling their move function
     * and updating the grid.
     */
    void Level::update() {
        enemiesThatCanShoot.clear();
        for (auto &enemyShip : enemyShips) {
            enemyShip->move();
            if (checkIfLowestEnemy(enemyShip)) {
                if (enemyShip->canShoot()) {
                    enemiesThatCanShoot.push_back(enemyShip);
                }
            }
        }
        for (auto bullet : flyingBullets) {
            bullet->move();
        }
        updateGrid();
    }

    /** Checks whether one of the game over conditions is triggered.
     * Function checks whether one of the game over/level over conditions is triggered (need to separate those)
     * @return Boolean that equals true if one of the conditions is triggered
     */
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

    bool Level::checkIfLowestEnemy(shared_ptr<BasicEnemy> checkedEnemy) {
        for (auto enemy : enemyShips) {
            if (enemy->getY() > checkedEnemy->getY() and enemy != checkedEnemy) {
                return false;
            }
        }
        return true;
    }
}

