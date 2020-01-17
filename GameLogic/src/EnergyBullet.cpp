//
// Created by student on 17.01.20.
//

#include "../Include/GameLogic/EnergyBullet.h"
#include "../../SFML/Include/EnergyBullet.h"


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
        //
    }
}

