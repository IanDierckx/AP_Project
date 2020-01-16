#include "../Include/utils.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

using namespace GameLogic;

namespace GameSFML{
    void scaleSprite(sf::Sprite& sprite, position upperLeft, position lowerRight) {
        double width = lowerRight.first-upperLeft.first;
        double heigth = lowerRight.second-upperLeft.second;
        auto scaleFactorX = static_cast<float>(width/sprite.getTextureRect().width);
        auto scaleFactorY = static_cast<float>(heigth/sprite.getTextureRect().height);
        sprite.scale(scaleFactorX,scaleFactorY);
    }
}