#include <iostream>
#include "../Include/Level.h"
#include "../Include/BasicEnemyBullet.h"


namespace GameSFML {

    /** Constructor of the SFML version of Level.
     * Constructor of the SFML version of Level.
     * @param window the current game window.
     */
    GameSFML::Level::Level(window_ptr &window) : window(window) {

    }

    /** Calls the draw function of all entities.
     * Calls the draw function of all entities.
     */
    void Level::draw() {
        for (const auto &enemy : enemyShips) {
            enemy->draw();
        }
        for (const auto &bullet : flyingBullets) {
            bullet->draw();

        }
        player->draw();
    }

    /** Extends the GameLogic version of the update function.
     * Extends the GameLogic version of the update function by creating new bullets if necessary,
     * checking for collisions and removing removable entities.
     */
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