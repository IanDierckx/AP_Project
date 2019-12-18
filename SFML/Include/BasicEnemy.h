#ifndef AP_PROJECT_SFML_BASICENEMY_H
#define AP_PROJECT_SFML_BASICENEMY_H


#include <SFML/Graphics.hpp>
#include <memory>
#include "../../GameLogic/Include/GameLogic/BasicEnemy.h"
#include "../../GameLogic/Include/GameLogic/Level.h"

namespace GameSFML{

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    class BasicEnemy : public GameLogic::BasicEnemy {
        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:
            BasicEnemy(const pair<int, int> &position, const string &fileName,
                       GameSFML::window_ptr window);

            void draw();

            void updateSprite();
    };
}


#endif //AP_PROJECT_SFML_BASICENEMY_H
