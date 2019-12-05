#ifndef AP_PROJECT_GAME_H
#define AP_PROJECT_GAME_H

#include "Stopwatch.h"
#include "Entity.h"

#include <vector>

using namespace std;

//Class that combines all parts
class Game {
private:
    vector<vector<pair<bool,Entity*>>> grid;

    int grid_x = 9;
    int grid_y = 7;
public:
    void initializeLevel();

    void printLevel();
};


#endif //AP_PROJECT_GAME_H
