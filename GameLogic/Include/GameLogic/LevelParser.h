#ifndef AP_PROJECT_LEVELPARSER_H
#define AP_PROJECT_LEVELPARSER_H

#include "../lib/json.hpp"
#include "../../../SFML/Include/Level.h"

// for convenience
using json = nlohmann::json;

namespace GameSFML{
    class LevelParser {
        private:
            json imported_json;
            window_ptr window;
        public:
            LevelParser(const string &levelFile, window_ptr window);

            shared_ptr<GameSFML::Level> parseJson();
        };
}




#endif //AP_PROJECT_LEVELPARSER_H
