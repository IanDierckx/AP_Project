//
// Created by student on 14.01.20.
//

#ifndef AP_PROJECT_PLAYER_H
#define AP_PROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../../GameLogic/Include/GameLogic/Player.h"

using namespace std;

namespace GameSFML{

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    class Player : public GameLogic::Player {
        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:
            Player(const pair<int, int> &position, double width, double height, const string &fileName,
                   GameSFML::window_ptr window);

            void draw() override;

            void updateSprite();
    };
}



#endif //AP_PROJECT_PLAYER_H
