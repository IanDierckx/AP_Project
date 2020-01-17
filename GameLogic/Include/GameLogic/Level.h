#ifndef AP_PROJECT_LEVEL_H
#define AP_PROJECT_LEVEL_H

#include "Player.h"
#include "BasicEnemy.h"
#include "Bullet.h"
#include "EnergyCannon.h"

#include <memory>

namespace GameLogic{

    /// Class to represent the levels inside the game
    class Level {
        protected:
            vector<shared_ptr<BasicEnemy>> enemyShips;

            vector<vector<pair<bool,shared_ptr<Entity>>>> grid;

            int grid_x = 9;
            int grid_y = 7;

            shared_ptr<Player> player;

            vector<shared_ptr<BasicEnemy>> enemiesThatCanShoot;

            vector<shared_ptr<Bullet>> flyingBullets;

            vector<shared_ptr<EnergyCannon>> cannons;

            int basicEnemyWidth = 48;
            int basicEnemyHeight = 29;

            int playerWidth = 44;
            int playerHeight = 36;

            int basicEnemyBulletWidth = 14;
            int basicEnemyBulletHeight = 25;

            int doubleShotEnemyWidth = 48;
            int doubleShotEnemyHeight = 27;

            int cannonWidth = 36;
            int cannonHeight = 34;

            int energyBulletWidth = 6;
            int energyBulletHeight = 18;
        public:

            /** Adds a new enemy ship to the level.
             * Function to add a new Ship entity to the vector of enemy ships
             * @param ship shared pointer to the new enemy ship to add
             */
            void addEnemyShip(shared_ptr<BasicEnemy> enemy);

            /** Updates the grid to accurately represent the current state of the game.
             * Function updates the state of the grid so all entity are in the correct position of the grid
             * according to their position value
             */
            void updateGrid();

            /** Adds a new row to the grid.
             * Function adds a new row to the grid, mostly used to add a empty row when setting up the grid
             * @param row Vector that represents the row that gets added to the grid
             */
            void addRow(vector<pair<bool, shared_ptr<Entity>>> row);

            /** Getter for the max x value of the grid set by the grid_x value of the class.
             *
             * @return Integer that is the max x value of the grid
             */
            int getGrid_x() const;

            /** Setter for the max x value of the grid set by the grid_x value of the class.
             *
             * @param grid_x The integer value to set the max x value of the grid to.
             */
            void setGrid_x(int grid_x);

            /** Getter for the max y value of the grid set by the grid_y value of the class.
            *
             * @return Integer that is the max y value of the grid
             */
            int getGrid_y() const;

            /** Setter for the max y value of the grid set by the grid_y value of the class.
            *
            * @param grid_y The integer value to set the max y value of the grid to.
            */
            void setGrid_y(int grid_y);

            /** Adds a new entity to the grid.
             * Adds a new entity to the grid. Position in the grid is determined by the position value of the entity
             * @param entity Shared pointer to the entity that needs to be added
             */
            void addEntityToGrid(shared_ptr<Entity> entity);

            /** Function to get the shared pointer to the player.
             * Returns the shared pointer to the player entity
             * @return The shared pointer to the player entity
             */
            shared_ptr<Player> getPlayer() const;

            /** Sets the player to the shared pointer of the player entity.
             * Set the player, used only when parsing the level
             * @param player The shared pointer to the p[ayer
             */
            void setPlayer(shared_ptr<Player> player);

            /** Updates the level.
             * Function updates the level by moving all enemies to their next position by calling their move function,
             * checking if enemies can fire and updating the grid.
             */
            virtual void update();

            /** Checks whether one of the game over conditions is triggered.
             * Function checks whether one of the game over/level over conditions is triggered (need to separate those)
             * @return Boolean that equals true if one of the conditions is triggered
             */
            bool gameOver();

            /** Checks if there are no enemies below the one checked.
             * Checks if there are no enemies below the one checked.
             * @param checkedEnemy the enemy we want to check
             * @return true if there are no enemies below it.
             */
            bool checkIfLowestEnemy(shared_ptr<BasicEnemy> checkedEnemy);

            /** Returns a vector of entities that should be deleted.
             * Returns a vector of entities that should be deleted.
             * @return A vector of entities that should be deleted.
             */
            vector<shared_ptr<Entity>> getRemovableEntities();

            /** Deletes all entities that aren't used anymore.
             * Deletes all entities that aren't used anymore.
             */
            void removeRemovableEntities();

            /** Checks if 2 entities collide.
             * Returns a boolean that represents is 2 entities collide or not.
             * @param entity1 First entity to check.
             * @param entity2 Second entity to check.
             * @return Returns true if the entities collide.
             */
            bool checkCollision(shared_ptr<Entity> entity1, shared_ptr<Entity> entity2);

            /** Returns the upperleft corner of the entity.
             * Returns the upperleft corner of the entity in the forms of a pair with the y coordinate first.
             * @param entity The entity we want the corner of.
             * @return The corner in the form of a pair with the y coordinate first.
             */
            pair<double, double> getUpperLeftCorner(shared_ptr<Entity> entity);

            /** Returns the lowerright corner of the entity.
             * Returns the lowerright corner of the entity in the forms of a pair with the y coordinate first.
             * @param entity The entity we want the corner of.
             * @return The corner in the form of a pair with the y coordinate first.
             */
            pair<double, double> getLowerRightCorner(shared_ptr<Entity> entity);

            /** Check if any entities collide.
             * Check if any entities collide.
             */
            void checkCollisionsOfAll();

            /** Adds a new cannon to the level.
             * Adds a new cannon to the level.
             * @param newCannon The cannon to add.
             */
            void addCannon(shared_ptr<EnergyCannon> newCannon);

            /** Returns the entity at the given position in the grid.
             * Returns the entity at the given position in the grid.
             * @param gridY Y coordinate of the grid.
             * @param gridX X coordinate of the grid.
             * @return If entity found a pointer to it, otherwise a nullpointer.
             */
            shared_ptr<Entity> getEntityInGrid(int gridY, int gridX);

            /** Getter for the width of the basic enemy.
             * Getter for the width of the basic enemy.
             * @return the width of the basic enemy.
             */
            int getBasicEnemyWidth() const;

            /** Getter for the height of the basic enemy.
             * Getter for the height of the basic enemy.
             * @return the height of the basic enemy.
             */
            int getBasicEnemyHeight() const;

            /** Getter for the width of the player.
             * Getter for the width of the player.
             * @return the width of the player.
             */
            int getPlayerWidth() const;

            /** Getter for the height of the player.
             * Getter for the height of the player.
             * @return the height of the player.
             */
            int getPlayerHeight() const;

            /** Getter for the width of the basic enemy bullet.
             * Getter for the width of the basic enemy bullet.
             * @return the width of the basic enemy bullet.
             */
            int getBasicEnemyBulletWidth() const;

            /** Getter for the height of the basic enemy bullet.
             * Getter for the height of the basic enemy bullet.
             * @return the height of the basic enemy bullet.
             */
            int getBasicEnemyBulletHeight() const;

            /** Getter for the width of the double shot enemy.
             * Getter for the width of the double shot enemy.
             * @return the width of the double shot enemy.
             */
            int getDoubleShotEnemyWidth() const;

            /** Getter for the height of the double shot enemy.
             * Getter for the height of the double shot enemy.
             * @return the height of the double shot enemy.
             */
            int getDoubleShotEnemyHeight() const;

            /** Getter for the width of the cannon.
             * Getter for the width of the cannon.
             * @return the width of the cannon.
             */
            int getCannonWidth() const;

            /** Getter for the height of the cannon.
             * Getter for the height of the cannon.
             * @return the height of the cannon.
             */
            int getCannonHeight() const;

            /** Getter for the width of the energy bullet.
             * Getter for the width of the energy bullet.
             * @return the width of the energy bullet.
             */
            int getEnergyBulletWidth() const;

            /** Getter for the height of the energy bullet.
             * Getter for the height of the energy bullet.
             * @return the height of the energy bullet.
             */
            int getEnergyBulletHeight() const;

            /** Creates a new EnergyBullet.
             * Creates a new EnergyBullet.
             * @param y The Y coordinate of the cannon that fires the bullet.
             * @param x The X coordinate of the cannon that fires the bullet.
             */
            virtual void createPlayerBullet(double y, double x);
    };
}



#endif //AP_PROJECT_LEVEL_H
