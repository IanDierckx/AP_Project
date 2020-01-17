#include <utility>

#include <utility>

#include "../Include/GameLogic/Level.h"
#include "../../SFML/Include/Level.h"
#include "../Include/GameLogic/Transformation.h"
#include "../Include/GameLogic/LogicUtils.h"
#include "../Include/GameLogic/EnergyBullet.h"


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

        for (const auto &cannon : cannons) {
            grid[cannon->getY()][cannon->getX()].first = true;
            grid[cannon->getY()][cannon->getX()].second = cannon;
        }

        grid[static_cast<int>(round(player->getMovingY()))][static_cast<int>(round(player->getMovingX()))].first = true;
        grid[static_cast<int>(round(player->getMovingY()))][static_cast<int>(round(player->getMovingX()))].second = player;
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
     * Function updates the level by moving all enemies to their next position by calling their move function,
     * checking if enemies can fire and updating the grid.
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
        for (const auto &bullet : flyingBullets) {
            bullet->move();
        }
        for (const auto &cannon : cannons) {
            cannon->autoReload();
            cannon->lowerDelay();
            cannon->increaseTimeNotUsed();
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
            if (std::abs(enemyShip->getMovingY() - 5) < 0.001) {
                return true;
            }
        }
        if (player->isDestroyed()) {
            return true;
        }
        return false;
    }

    /** Checks if there are no enemies below the one checked.
     * Checks if there are no enemies below the one checked.
     * @param checkedEnemy the enemy we want to check
     * @return true if there are no enemies below it.
     */
    bool Level::checkIfLowestEnemy(shared_ptr<BasicEnemy> checkedEnemy) {
        for (const auto &enemy : enemyShips) {
            if (enemy->getY() > checkedEnemy->getY() and enemy != checkedEnemy) {
                return false;
            }
        }
        return true;
    }

    /** Returns a vector of entities that should be deleted.
     * Returns a vector of entities that should be deleted.
     * @return A vector of entities that should be deleted.
     */
    vector<shared_ptr<Entity>> Level::getRemovableEntities() {
        vector<shared_ptr<Entity>> removableEntities;
        removableEntities.clear();
        for (const auto &bullet : flyingBullets) {
            if (bullet->checkIfRemovable()) {
                removableEntities.push_back(bullet);
            }
        }
        for (const auto &enemy : enemyShips) {
            if (enemy->checkIfRemovable()) {
                removableEntities.push_back(enemy);
            }
        }
        for (const auto &removable : removableEntities) {
            if (removable->getType() == "BasicEnemyBullet" or removable->getType() == "Bullet") {
                auto position = std::find(flyingBullets.begin(), flyingBullets.end(), removable);
                flyingBullets.erase(position);
            } else if (removable->getType() == "BasicEnemy") {
                auto position = std::find(enemyShips.begin(), enemyShips.end(), removable);
                enemyShips.erase(position);
            }
        }
        return removableEntities;
    }

    /** Deletes all entities that aren't used anymore.
     * Deletes all entities that aren't used anymore.
     */
    void Level::removeRemovableEntities() {
        auto removableEntities = getRemovableEntities();
        for (auto entity : removableEntities) {
            entity.reset();
        }
    }

    /** Checks if 2 entities collide.
     * Returns a boolean that represents is 2 entities collide or not.
     * @param entity1 First entity to check.
     * @param entity2 Second entity to check.
     * @return Returns true if the entities collide.
     */
    bool Level::checkCollision(shared_ptr<Entity> entity1, shared_ptr<Entity> entity2) {
        if (entity2->getMovingY() < entity1->getMovingY()) {
            auto temp = std::move(entity2);
            entity2 = std::move(entity1);
            entity1 = std::move(temp);
        }

        auto e1UpperLeftCorner = getUpperLeftCorner(entity1);
        auto e2UpperLeftCorner = getUpperLeftCorner(entity2);
        auto e1LowerRightCorner = getLowerRightCorner(entity1);
        auto e2LowerRightCorner = getLowerRightCorner(entity2);


        if (e1LowerRightCorner.first > e2UpperLeftCorner.first) {
            if (e2UpperLeftCorner.second < e1LowerRightCorner.second and e2LowerRightCorner.second > e1LowerRightCorner.second) {
                return true;
            }
        }
        return false;
    }

    /** Returns the upperleft corner of the entity.
     * Returns the upperleft corner of the entity in the forms of a pair with the y coordinate first.
     * @param entity The entity we want the corner of.
     * @return The corner in the form of a pair with the y coordinate first.
     */
    pair<double, double> Level::getUpperLeftCorner(shared_ptr<Entity> entity) {
        auto transf = Transformation::getInstance();
        double upperLeftX = transf->convertXToScreen(entity->getMovingX()) - entity->getWidth()/2;
        double upperLeftY = transf->convertYToScreen(entity->getMovingY()) - entity->getHeight()/2;
        return make_pair(upperLeftY, upperLeftX);
    }

    /** Returns the lowerright corner of the entity.
     * Returns the lowerright corner of the entity in the forms of a pair with the y coordinate first.
     * @param entity The entity we want the corner of.
     * @return The corner in the form of a pair with the y coordinate first.
     */
    pair<double, double> Level::getLowerRightCorner(shared_ptr<Entity> entity) {
        auto transf = Transformation::getInstance();
        double loweRightX = transf->convertXToScreen(entity->getMovingX()) + entity->getWidth()/2;
        double loweRightY = transf->convertYToScreen(entity->getMovingY()) + entity->getHeight()/2;
        return make_pair(loweRightY, loweRightX);
    }

    /** Check if any entities collide.
     * Check if any entities collide.
     */
    void Level::checkCollisionsOfAll() {
        vector<shared_ptr<Entity>> allEntities;
        allEntities.push_back(player);
        for (const auto &bullet : flyingBullets) {
            allEntities.push_back(bullet);
        }
        for (const auto &enemy : enemyShips) {
            allEntities.push_back(enemy);
        }
        for (const auto &entity1 : allEntities) {
            for (const auto &entity2 : allEntities) {
                if (entity1 == entity2) {
                    continue;
                }
                if (checkCollision(entity1, entity2)) {
                    entity1->handleCollision(entity2);
                }
            }
        }
    }

    /** Adds a new cannon to the level.
     * Adds a new cannon to the level.
     * @param newCannon The cannon to add.
     */
    void Level::addCannon(shared_ptr<EnergyCannon> newCannon) {
        cannons.push_back(newCannon);
    }

    /** Returns the entity at the given position in the grid.
     * Returns the entity at the given position in the grid.
     * @param gridY Y coordinate of the grid.
     * @param gridX X coordinate of the grid.
     * @return If entity found a pointer to it, otherwise a nullpointer.
     */
    shared_ptr<Entity> Level::getEntityInGrid(int gridY, int gridX) {
        return grid[gridY][gridX].second;
    }

    /** Getter for the width of the basic enemy.
     * Getter for the width of the basic enemy.
     * @return the width of the basic enemy.
     */
    int Level::getBasicEnemyWidth() const {
        return basicEnemyWidth;
    }

    /** Getter for the height of the basic enemy.
     * Getter for the height of the basic enemy.
     * @return the height of the basic enemy.
     */
    int Level::getBasicEnemyHeight() const {
        return basicEnemyHeight;
    }

    /** Getter for the width of the player.
     * Getter for the width of the player.
     * @return the width of the player.
     */
    int Level::getPlayerWidth() const {
        return playerWidth;
    }

    /** Getter for the height of the player.
     * Getter for the height of the player.
     * @return the height of the player.
     */
    int Level::getPlayerHeight() const {
        return playerHeight;
    }

    /** Getter for the width of the basic enemy bullet.
     * Getter for the width of the basic enemy bullet.
     * @return the width of the basic enemy bullet.
     */
    int Level::getBasicEnemyBulletWidth() const {
        return basicEnemyBulletWidth;
    }

    /** Getter for the height of the basic enemy bullet.
     * Getter for the height of the basic enemy bullet.
     * @return the height of the basic enemy bullet.
     */
    int Level::getBasicEnemyBulletHeight() const {
        return basicEnemyBulletHeight;
    }

    /** Getter for the width of the double shot enemy.
     * Getter for the width of the double shot enemy.
     * @return the width of the double shot enemy.
     */
    int Level::getDoubleShotEnemyWidth() const {
        return doubleShotEnemyWidth;
    }

    /** Getter for the height of the double shot enemy.
     * Getter for the height of the double shot enemy.
     * @return the height of the double shot enemy.
     */
    int Level::getDoubleShotEnemyHeight() const {
        return doubleShotEnemyHeight;
    }

    /** Getter for the width of the cannon.
     * Getter for the width of the cannon.
     * @return the width of the cannon.
     */
    int Level::getCannonWidth() const {
        return cannonWidth;
    }

    /** Getter for the height of the cannon.
     * Getter for the height of the cannon.
     * @return the height of the cannon.
     */
    int Level::getCannonHeight() const {
        return cannonHeight;
    }

    /** Getter for the width of the energy bullet.
     * Getter for the width of the energy bullet.
     * @return the width of the energy bullet.
     */
    int Level::getEnergyBulletWidth() const {
        return energyBulletWidth;
    }

    /** Getter for the height of the energy bullet.
     * Getter for the height of the energy bullet.
     * @return the height of the energy bullet.
     */
    int Level::getEnergyBulletHeight() const {
        return energyBulletHeight;
    }

    void Level::createPlayerBullet(double y, double x) {
//        auto bullet = make_shared<EnergyBullet>(make_pair(y, x), getEnergyBulletWidth(), getEnergyBulletHeight());
//        flyingBullets.push_back(bullet);
    }


}

