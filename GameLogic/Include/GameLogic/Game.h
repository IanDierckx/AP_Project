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
    protected:

    public:
        virtual void initializeLevel(const string &levelFile);

        virtual void run();

    };
}



#endif //AP_PROJECT_GAME_H
