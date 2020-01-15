#include <iostream>
#include "../Include/Level.h"
#include "../Include/BasicEnemyBullet.h"


namespace GameSFML {

    GameSFML::Level::Level(window_ptr &window) : window(window) {

    }

    void Level::draw() {
        for (const auto &enemy : enemyShips) {
            enemy->draw();
        }
        for (const auto bullet : flyingBullets) {
            bullet->draw();

        }
        player->draw();
    }

    void Level::update() {
        GameLogic::Level::update();
        for (auto ship:enemiesThatCanShoot) {
            shared_ptr<BasicEnemyBullet> bullet = make_shared<BasicEnemyBullet>(make_pair(ship->getY(), ship->getX()),
                    64, 64, "EnemyBullet.png", window);
            flyingBullets.push_back(bullet);
        }

    }

}