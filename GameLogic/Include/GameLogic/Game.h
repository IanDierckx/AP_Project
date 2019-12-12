#ifndef AP_PROJECT_GAME_H
#define AP_PROJECT_GAME_H

#include "Stopwatch.h"
#include "Entity.h"
#include "Ship.h"
#include "LevelParser.h"

#include <vector>

using namespace std;

namespace GameLogic{
    //Class that combines all parts
    class Game {
    private:
        Level currentLevel;

    public:
        void initializeLevel(string levelFile);

        void run();

    };
}



#endif //AP_PROJECT_GAME_H
