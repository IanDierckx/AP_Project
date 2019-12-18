#ifndef AP_PROJECT_SFML_GAME_H
#define AP_PROJECT_SFML_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../../GameLogic/Include/GameLogic/Game.h"
#include "Game.h"

using namespace std;

namespace GameSFML{
    class Game : public GameLogic::Game{
        private:
            shared_ptr<sf::RenderWindow> window;
            shared_ptr<Level> currentLevel;
        public:
            Game(const string& title = "Space Invaders");

            void initializeLevel(string levelFile) override;

            void run() override;
    };
}

#endif //AP_PROJECT_SFML_GAME_H
