#include "../Include/utils.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

using namespace GameLogic;

namespace GameSFML{
    void scaleSprite(sf::Sprite& sprite, position upperLeft, position lowerRight) {
        double width = lowerRight.first-upperLeft.first;
        double heigth = lowerRight.second-upperLeft.second;
        float scaleFactorX = static_cast<float>(width/sprite.getTexture()->getSize().x);
        float scaleFactorY = static_cast<float>(heigth/sprite.getTexture()->getSize().y);
        sprite.scale(scaleFactorX,scaleFactorY);
    }
}