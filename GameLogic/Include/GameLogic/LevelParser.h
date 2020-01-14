#ifndef AP_PROJECT_LEVELPARSER_H
#define AP_PROJECT_LEVELPARSER_H

#include "../lib/json.hpp"
#include "../../../SFML/Include/Level.h"

// for convenience
using json = nlohmann::json;

namespace GameSFML{

    /// Class to help parse json files that represent the levels of the game
    class LevelParser {
        private:
            json imported_json;
            window_ptr window;
        public:

            /// Constructor of the parser class
            LevelParser(const string &levelFile, window_ptr window);

            /// The actual parsing function
            /***
             * Function parses the json file that was imported in the constructor
             * @return Shared pointer to the created Level
             */
            shared_ptr<GameSFML::Level> parseJson();
        };
}




#endif //AP_PROJECT_LEVELPARSER_H
