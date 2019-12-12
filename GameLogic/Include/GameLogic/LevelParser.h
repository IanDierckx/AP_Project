#ifndef AP_PROJECT_LEVELPARSER_H
#define AP_PROJECT_LEVELPARSER_H

#include "../lib/json.hpp"
#include "Ship.h"
#include "PlayerShip.h"
#include "Level.h"

// for convenience
using json = nlohmann::json;

namespace GameLogic{
    class LevelParser {
        private:
            json imported_json;
        public:
            explicit LevelParser(string levelFile);

            Level parseJson();
        };
}




#endif //AP_PROJECT_LEVELPARSER_H
