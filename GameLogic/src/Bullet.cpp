//
// Created by student on 15.01.20.
//

#include "../Include/GameLogic/Bullet.h"

namespace GameLogic {
    /** Constructor for Bullet class.
     * Constructor for Bullet class.
     * @param position the starting position of the bullet
     * @param width the width of the bullet.
     * @param height the height of the bullet.
     */
    Bullet::Bullet(const pair<int, int> &position, double width, double height)
    : Entity(position, width, height) {
        setSpeed(0.2);
        setType("Bullet");
    }

    /** Virtual function determines what happens when the bullet hits an Entity.
     * Function determines what happens when the bullet hits an Entity. What exactly happens depends on
     * the type of bullet and the type of Entity.
     * @param hitEntity Shared_ptr to the Entity that was hit.
     */
    void Bullet::hit(shared_ptr<Entity> hitEntity) {
        ///Virtual function, actual implementation depends on the subclass of bullet.
    }
}
