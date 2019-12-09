#ifndef AP_PROJECT_GAME_H
#define AP_PROJECT_GAME_H

#include "Stopwatch.h"
#include "Entity.h"
#include "Ship.h"

#include <vector>

using namespace std;

//Class that combines all parts
class Game {
private:
    vector<vector<pair<bool,Entity*>>> grid;

    int grid_x = 9;
    int grid_y = 7;

    vector<Ship*> enemyShips;
public:
    void initializeLevel();

    void addEntityToGrid(Entity* entity);

    void printLevel();

    void run();

    void moveEntity(Entity* entity);
};


#endif //AP_PROJECT_GAME_H
