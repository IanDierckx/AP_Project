#include <utility>

#include "../Include/DoubleShotEnemy.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

namespace GameSFML{

    GameSFML::DoubleShotEnemy::DoubleShotEnemy(const pair<int, int> &position, double width, double height,
                                               const string &fileName, GameSFML::window_ptr window) :
                                               GameLogic::DoubleShotEnemy(position, width, height), window(
            std::move(window)) {
        string spritesPath = "./SFML/res/sprites/";
        try {
            if(!texture.loadFromFile(spritesPath+fileName)) {
                throw 1;
            };
        }
        catch (int e) {
            cout << "Unable to load double shot enemy sprite" << endl;
        }
        sprite = Sprite(texture);
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    }

    /** Updates the sprite and draws it to the window.
     * Updates the sprite and draws it to the window.
     */
    void DoubleShotEnemy::draw() {
        updateSprite();
        window->draw(sprite);
    }

    /** Updates the sprite to the current position.
     * Updates the sprite to the current position.
     */
    void DoubleShotEnemy::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(this->getMovingX(), this->getMovingY());
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}


