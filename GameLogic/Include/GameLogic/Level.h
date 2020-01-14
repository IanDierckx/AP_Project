//
// Created by student on 12.12.19.
//

#ifndef AP_PROJECT_LEVEL_H
#define AP_PROJECT_LEVEL_H

#include "Player.h"

#include <memory>

namespace GameLogic{
    class Level {
        protected:
            vector<shared_ptr<Ship>> enemyShips;

            vector<vector<pair<bool,shared_ptr<Entity>>>> grid;

            int grid_x = 9;
            int grid_y = 7;

            shared_ptr<Player> player;
        public:
            void addEnemyShip(shared_ptr<Ship> ship);

            void updateGrid();

            void addRow(vector<pair<bool, shared_ptr<Entity>>> row);

            int getGrid_x() const;

            void setGrid_x(int grid_x);

            int getGrid_y() const;

            void setGrid_y(int grid_y);

            void addEntityToGrid(shared_ptr<Entity> entity);

            void printLevel();

            shared_ptr<Player> getPlayer() const;

            void setPlayer(shared_ptr<Player> player);

            void update();

            bool gameOver();
    };
}



#endif //AP_PROJECT_LEVEL_H
