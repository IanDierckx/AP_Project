#ifndef AP_PROJECT_SFML_ENERGYBULLET_H
#define AP_PROJECT_SFML_ENERGYBULLET_H

#include <SFML/Graphics.hpp>
#include "../../GameLogic/Include/GameLogic/EnergyBullet.h"

namespace GameSFML{

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    class EnergyBullet : public GameLogic::EnergyBullet {
        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:

            /** Constructor of the SFML BasicEnemyBullet.
             * Constructor of the SFML EnergyBullet.
             * @param position Position in the grid of the bullet
             * @param width width of the bullet
             * @param height height of the bullet
             * @param fileName name of the file of the sprite of the bullet
             * @param window current game window
             */
            EnergyBullet(const pair<int, int> &position, double width, double height, const string &fileName,
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



#endif //AP_PROJECT_SFML_ENERGYBULLET_H
