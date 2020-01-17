#include "../Include/BasicEnemyBullet.h"
#include "../Include/utils.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

namespace GameSFML{

    /** Constructor of the SFML BasicEnemyBullet.
     * Constructor of the SFML BasicEnemyBullet.
     * @param position Position in the grid of the bullet
     * @param width width of the bullet
     * @param height height of the bullet
     * @param fileName name of the file of the sprite of the bullet
     * @param window current game window
     */
    GameSFML::BasicEnemyBullet::BasicEnemyBullet(const pair<int, int> &position, double width, double height,
                                                 const string &fileName, const GameSFML::window_ptr &window)
            : GameLogic::BasicEnemyBullet(position, width, height), window(window) {
        string spritesPath = "./SFML/res/sprites/";
        texture.loadFromFile(spritesPath+fileName);
        sprite = Sprite(texture);
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
        pair<double, double> upperLeft = make_pair(sprite.getOrigin().x - width/2, sprite.getOrigin().y - height/2);
        pair<double, double> lowerRight = make_pair(sprite.getOrigin().x + width/2, sprite.getOrigin().y + height/2);
//        scaleSprite(sprite, upperLeft, lowerRight);
    }

    /** Updates the sprite and draws it to the window.
     * Updates the sprite and draws it to the window.
     */
    void BasicEnemyBullet::draw() {
        updateSprite();
        window->draw(sprite);
    }

    /** Updates the sprite to the current position.
     * Updates the sprite to the current position.
     */
    void BasicEnemyBullet::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(getMovingX(), getMovingY());
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}
