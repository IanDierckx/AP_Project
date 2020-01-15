#ifndef AP_PROJECT_SFML_BASICENEMYBULLET_H
#define AP_PROJECT_SFML_BASICENEMYBULLET_H


#include <SFML/Graphics.hpp>
#include "../../GameLogic/Include/GameLogic/BasicEnemyBullet.h"

namespace GameSFML{

    using window_ptr = shared_ptr<sf::RenderWindow>;
    using namespace sf;

    /** SFML version of the Basic Enemy's bullet.
     * SFML version of the Basic Enemy's bullet.
     */
    class BasicEnemyBullet : public GameLogic::BasicEnemyBullet {
        private:
            window_ptr window;
            Texture texture;
            Sprite sprite;
        public:

        /** Constructor of the SFML BasicEnemyBullet.
         * Constructor of the SFML BasicEnemyBullet.
         * @param position Position in the grid of the bullet
         * @param width width of the bullet
         * @param height height of the bullet
         * @param fileName name of the file of the sprite of the bullet
         * @param window current game window
         */
        BasicEnemyBullet(const pair<int, int> &position, double width, double height, const string &fileName,
                const window_ptr &window);

        void draw() override;

        void updateSprite();
    };
}



#endif //AP_PROJECT_SFML_BASICENEMYBULLET_H
