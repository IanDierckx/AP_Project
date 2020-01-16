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
        for (const auto &bullet : flyingBullets) {
            bullet->draw();

        }
        player->draw();
    }

    void Level::update() {
        GameLogic::Level::update();
        for (const auto &ship:enemiesThatCanShoot) {
            shared_ptr<BasicEnemyBullet> bullet = make_shared<BasicEnemyBullet>(make_pair(ship->getY(), ship->getX()),
                    32, 32, "EnemyBullet.png", window);
            flyingBullets.push_back(bullet);
        }
        checkCollisionsOfAll();
        removeRemovableEntities();
    }

}