//
// Created by student on 17.01.20.
//

#include <iostream>
#include "../Include/GameLogic/EnergyBullet.h"
#include "../../SFML/Include/EnergyBullet.h"
#include "../Include/GameLogic/BasicEnemy.h"


namespace GameLogic{
    /** Constructor for the Game Logic version of EnergyBullet.
     * Constructor for the Game Logic version of EnergyBullet.
     * @param position the starting position of the bullet
     * @param width the width of the bullet.
     * @param height the height of the bullet.
     */
    GameLogic::EnergyBullet::EnergyBullet(const pair<int, int> &position, double width, double height)
        : Bullet(position, width, height) {
            setType("EnergyBullet");
            setSpeed(-0.2);
    }

    /** Handles what happens if the bullet collides with another entity.
     * Handles what happens if the bullet collides with another entity.
     * @param otherEntity the other entity it collides with.
     */
    void EnergyBullet::handleCollision(const shared_ptr<Entity> &otherEntity) {
        if (otherEntity->getType() == "BasicEnemy" or otherEntity->getType() == "doubleShotEnemy") {
//            cout << "Energy bullet hit " << otherEntity->getType() << endl;
            shared_ptr<BasicEnemy> enemy = dynamic_pointer_cast<BasicEnemy>(otherEntity);
            if (otherEntity->getType() == "doubleShotEnemy") {
                auto test = 0;
            }
            enemy->setHealth(enemy->getHealth()-1);
            if (enemy->getHealth() == 0) {
                enemy->remove();
            }
            remove();
        }
    }
}

