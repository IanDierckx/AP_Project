#ifndef AP_PROJECT_LEVEL_H
#define AP_PROJECT_LEVEL_H

#include "Player.h"
#include "BasicEnemy.h"
#include "Bullet.h"

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
             * Function updates the level by moving all enemies to their next position by calling their move function
             * and updating the grid.
             */
            void update();

            /** Checks whether one of the game over conditions is triggered.
             * Function checks whether one of the game over/level over conditions is triggered (need to separate those)
             * @return Boolean that equals true if one of the conditions is triggered
             */
            bool gameOver();

            bool checkIfLowestEnemy(shared_ptr<BasicEnemy> checkedEnemy);
    };
}



#endif //AP_PROJECT_LEVEL_H
