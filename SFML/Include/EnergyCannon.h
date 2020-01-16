#ifndef AP_PROJECT_SFML_ENERGYCANNON_H
#define AP_PROJECT_SFML_ENERGYCANNON_H

#include <SFML/Graphics.hpp>
#include "../../GameLogic/Include/GameLogic/EnergyCannon.h"

namespace GameSFML{

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    /** SFML version of the EnergyCannon class.
     * SFML version of the EnergyCannon class.
     */
    class EnergyCannon : public GameLogic::EnergyCannon {

        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:

        /** Constructor of the SFML version of EnergyCannon.
         * Constructor of the SFML version of EnergyCannon.
         * @param position The position in the grid of the cannon.
         * @param width The width of the cannon.
         * @param height The height of the cannon.
         * @param fileName The name of the file that contains the sprite of the cannon.
         * @param window The current game window
         */
        EnergyCannon(const pair<int, int> &position, double width, double height, const string &fileName,
                const window_ptr &window);

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




#endif //AP_PROJECT_SFML_ENERGYCANNON_H
