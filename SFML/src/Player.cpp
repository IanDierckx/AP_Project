#include <utility>
#include <iostream>

#include "../Include/Player.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

namespace GameSFML{

    /** Constructor of the SFML version of the player.
     * Constructor of the SFML version of the player.
     *  @param position The position of the player in the grid
     * @param width The width of the player
     * @param height The height of the player
     * @param fileName The name of the file that contains the player's sprite.
     * @param window The current game window.
     */
    GameSFML::Player::Player(const pair<int, int> &position, double width, double height, const string &fileName,
                             GameSFML::window_ptr window): GameLogic::Player(position, width, height), window(
            std::move(window)) {
        string spritesPath = "./SFML/res/sprites/";
        try {
            if(!texture.loadFromFile(spritesPath+fileName)) {
                throw 1;
            };
        }
        catch (int e) {
            cout << "Unable to load player sprite" << endl;
        }
        sprite = Sprite(texture, sf::IntRect(0,0, 64, 64));
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    }

    /** Updates the sprite and draws it to the window.
     * Updates the sprite and draws it to the window.
     */
    void GameSFML::Player::draw() {
        updateSprite();
        window->draw(sprite);
    }

    /** Updates the sprite to the current position.
     * Updates the sprite to the current position.
     */
    void GameSFML::Player::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(this->getMovingX(), this->getMovingY());
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}


