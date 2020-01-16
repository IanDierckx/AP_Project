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
            /** Constructor of the SFML version of the player.
             * Constructor of the SFML version of the player.
             *  @param position The position of the player in the grid
             * @param width The width of the player
             * @param height The height of the player
             * @param fileName The name of the file that contains the player's sprite.
             * @param window The current game window.
             */
            Player(const pair<int, int> &position, double width, double height, const string &fileName,
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



#endif //AP_PROJECT_PLAYER_H
