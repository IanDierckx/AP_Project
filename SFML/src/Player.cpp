#include <utility>

#include "../Include/Player.h"
#include "../Include/utils.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

GameSFML::Player::Player(const pair<int, int> &position, double width, double height, const string &fileName,
                         GameSFML::window_ptr window): GameLogic::Player(position, width, height), window(
        std::move(window)) {
    string spritesPath = "./SFML/res/sprites/";
    texture.loadFromFile(spritesPath+fileName);
    sprite = Sprite(texture, sf::IntRect(0,0, 64, 64));
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    pair<double, double> upperLeft = make_pair(sprite.getOrigin().x - width/2, sprite.getOrigin().y - height/2);
    pair<double, double> lowerRight = make_pair(sprite.getOrigin().x + width/2, sprite.getOrigin().y + height/2);
//    scaleSprite(sprite, upperLeft, lowerRight);
}

void GameSFML::Player::draw() {
    updateSprite();
    window->draw(sprite);
}

void GameSFML::Player::updateSprite() {
    auto transf = GameLogic::Transformation::getInstance();
    pair<double, double> screenPos = transf->convertToScreen(this->getMovingX(), this->getMovingY());
    sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
}
