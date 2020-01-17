#include <iostream>
#include "../Include/EnergyBullet.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

namespace GameSFML{
    GameSFML::EnergyBullet::EnergyBullet(const pair<int, int> &position, double width, double height,
                                         const string &fileName, const window_ptr &window)
                                         : GameLogic::EnergyBullet(position, width, height), window(window) {
        string spritesPath = "./SFML/res/sprites/";
        try {
            if(!texture.loadFromFile(spritesPath+fileName)) {
                throw 1;
            };
        }
        catch (int e) {
            cout << "Unable to load energy bullet sprite" << endl;
        }
        sprite = Sprite(texture);
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    }

    /** Updates the sprite and draws it to the window.
     * Updates the sprite and draws it to the window.
     */
    void EnergyBullet::draw() {
        updateSprite();
        window->draw(sprite);
    }

    /** Updates the sprite to the current position.
     * Updates the sprite to the current position.
     */
    void EnergyBullet::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(getMovingX(), getMovingY());
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}