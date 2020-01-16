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
            /** Constructor of the SFML version of Basic Enemy.
             * Constructor of the SFML version of Basic Enemy.
             * @param position The position of the basic enemy in the grid
             * @param width The width of the basic enemy
             * @param height The height of the basic enemy
             * @param fileName The name of the file that contains the sprite
             * @param window The current game window.
             */
            BasicEnemy(const pair<int, int> &position, double width, double height, const string &fileName,
                       GameSFML::window_ptr window);

            /** Updates the sprite and draws it to the window.
             * Updates the sprite and draws it to the window.
             */
            void draw() override;

            /** Updates the sprite to the current position.
             * Updates the sprite to the current position.
             */
            void updateSprite();
    };
}


#endif //AP_PROJECT_SFML_BASICENEMY_H
