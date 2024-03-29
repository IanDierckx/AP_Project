#include <iostream>
#include "../Include/GameLogic/Bullet.h"
#include "../Include/GameLogic/Transformation.h"
#include "../Include/GameLogic/LogicUtils.h"

namespace GameLogic {
    /** Constructor for Bullet class.
     * Constructor for Bullet class.
     * @param position the starting position of the bullet
     * @param width the width of the bullet.
     * @param height the height of the bullet.
     */
    Bullet::Bullet(const pair<int, int> &position, double width, double height)
    : Entity(position, width, height) {
        setSpeed(0.125);
        setType("Bullet");
    }

//    /** Virtual function determines what happens when the bullet hits an Entity.
//     * Function determines what happens when the bullet hits an Entity. What exactly happens depends on
//     * the type of bullet and the type of Entity.
//     * @param hitEntity Shared_ptr to the Entity that was hit.
//     */
//    void Bullet::hit(const shared_ptr<Entity> &hitEntity) {
//        ///Virtual function, actual implementation depends on the subclass of bullet.
//    }

    /** Moves the bullet up or down according to speed.
     * Moves the bullet up or down according to speed.
     */
    void Bullet::move() {
        auto transf = Transformation::getInstance();
        if (getMovingY() > 9 or getMovingY() < 0) {
            remove();
        }
        if (isDoubleEqualToInt(getMovingY(), getY())) {
            if (getSpeed() > 0) {
                setY(getY()+1);
            } else {
                setY(getY()-1);
            }
        }
        if (!isDoubleEqualToInt(getMovingY(),getY())) {
           addMovingY(getSpeed());
        }
    }

//    /** Virtual draw function of the bullet class.
//     * Virtual draw function of the bullet class.
//     */
//    void Bullet::draw() {
//        // Virtual draw function of the bullet class.
//    }
}
