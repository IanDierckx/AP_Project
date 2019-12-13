//
// Created by student on 12.12.19.
//

#ifndef AP_PROJECT_LEVEL_H
#define AP_PROJECT_LEVEL_H

#include "PlayerShip.h"

namespace GameLogic{
    class Level {
        private:
            vector<Ship*> enemyShips;

            vector<vector<pair<bool,Entity*>>> grid;

            int grid_x = 9;
            int grid_y = 7;

            PlayerShip* player;
        public:
            void addEnemyShip(Ship* ship);

            void updateGrid();

            void addRow(vector<pair<bool, Entity *>> row);

            int getGrid_x() const;

            void setGrid_x(int grid_x);

            int getGrid_y() const;

            void setGrid_y(int grid_y);

            void addEntityToGrid(Entity* entity);

            void printLevel();

            PlayerShip *getPlayer() const;

            void setPlayer(PlayerShip *player);

            void update();

            bool gameOver();
    };
}



#endif //AP_PROJECT_LEVEL_H
