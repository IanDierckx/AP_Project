//
// Created by student on 18.12.19.
//

#include "../Include/Level.h"


namespace GameSFML {

    GameSFML::Level::Level(window_ptr &window) : window(window) {

    }

    void Level::draw() {
        for (auto enemy : enemyShips) {
            enemy->draw();
        }
    }

}