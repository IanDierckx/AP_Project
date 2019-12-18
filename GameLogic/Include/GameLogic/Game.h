#ifndef AP_PROJECT_GAME_H
#define AP_PROJECT_GAME_H

#include "Stopwatch.h"
#include "Entity.h"
#include "Ship.h"
#include "../../../SFML/Include/LevelParser.h"

#include <vector>

using namespace std;

namespace GameLogic{
    //Class that combines all parts
    class Game {
    protected:

    public:
        virtual void initializeLevel(string levelFile);

        virtual void run();

    };
}



#endif //AP_PROJECT_GAME_H
