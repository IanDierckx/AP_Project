#include "../Include/BasicEnemy.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"
#include "../Include/utils.h"

namespace GameSFML{
    BasicEnemy::BasicEnemy(const pair<int, int> &position, double width, double height, const string &fileName,
             const GameSFML::window_ptr window)
            : GameLogic::BasicEnemy(position, width, height), window(window){
        string spritesPath = "./SFML/res/sprites/";
        texture.loadFromFile(spritesPath+fileName);
        sprite = Sprite(texture);
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
        pair<double, double> upperLeft = make_pair(sprite.getOrigin().x - width/2, sprite.getOrigin().y - height/2);
        pair<double, double> lowerRight = make_pair(sprite.getOrigin().x + width/2, sprite.getOrigin().y + height/2);
        scaleSprite(sprite, upperLeft, lowerRight);
    }

    void BasicEnemy::draw() {
        updateSprite();
        window->draw(sprite);
    }

    void BasicEnemy::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(this->getMovingX(), this->getMovingY());
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}
