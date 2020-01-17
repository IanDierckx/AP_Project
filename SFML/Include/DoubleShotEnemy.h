#ifndef AP_PROJECT_SFML_DOUBLESHOTENEMY_H
#define AP_PROJECT_SFML_DOUBLESHOTENEMY_H

#include <SFML/Graphics.hpp>
#include "../../GameLogic/Include/GameLogic/DoubleShotEnemy.h"

namespace GameSFML {

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    class DoubleShotEnemy : public GameLogic::DoubleShotEnemy {
        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:
            /** Constructor of the SFML version of Double Shot Enemy.
             * Constructor of the SFML version of Double Shot Enemy.
             * @param position The position of the Double Shot enemy in the grid
             * @param width The width of the Double Shot enemy
             * @param height The height of the Double Shot enemy
             * @param fileName The name of the file that contains the sprite
             * @param window The current game window.
             */
            DoubleShotEnemy(const pair<int, int> &position, double width, double height, const string &fileName,
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



#endif //AP_PROJECT_SFML_DOUBLESHOTENEMY_H
