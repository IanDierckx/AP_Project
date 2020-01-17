#include <iostream>
#include "../Include/EnergyCannon.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"


namespace GameSFML{

    EnergyCannon::EnergyCannon(const pair<int, int> &position, double width, double height, const string &fileName,
                               const window_ptr &window) :
                               GameLogic::EnergyCannon(position, width, height), window(window) {
        string spritesPath = "./SFML/res/sprites/";
        try {
            if(!texture.loadFromFile(spritesPath+fileName)) {
                throw 1;
            };
        }
        catch (int e) {
            cout << "Unable to load cannon sprite" << endl;
        }
        sprite = Sprite(texture, sf::IntRect(0,0, 64, 64));
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    }

    void EnergyCannon::draw() {
        updateSprite();
        window->draw(sprite);
    }

    void EnergyCannon::updateSprite() {
        auto transf = GameLogic::Transformation::getInstance();
        pair<double, double> screenPos = transf->convertToScreen(getX(), getY());
        switch (remainingBullets) {
            case 8:
                sprite = Sprite(texture, sf::IntRect(0, 0, 64, 64));
                break;
            case 7:
                sprite = Sprite(texture, sf::IntRect(64, 0, 64, 64));
                break;
            case 6:
                sprite = Sprite(texture, sf::IntRect(128, 0, 64, 64));
                break;
            case 5:
                sprite = Sprite(texture, sf::IntRect(192, 0, 64, 64));
                break;
            case 4:
                sprite = Sprite(texture, sf::IntRect(256, 0, 64, 64));
                break;
            case 3:
                sprite = Sprite(texture, sf::IntRect(320, 0, 64, 64));
                break;
            case 2:
                sprite = Sprite(texture, sf::IntRect(384, 0, 64, 64));
                break;
            case 1:
                sprite = Sprite(texture, sf::IntRect(448, 0, 64, 64));
                break;
            case 0:
                sprite = Sprite(texture, sf::IntRect(512, 0, 64, 64));
                break;
            default:
                sprite = Sprite(texture, sf::IntRect(512, 0, 64, 64));
                break;
        }
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
        sprite.setPosition(static_cast<float>(screenPos.first), static_cast<float>(screenPos.second));
    }
}

