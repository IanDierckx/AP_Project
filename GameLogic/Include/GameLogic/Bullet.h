#ifndef AP_PROJECT_BULLET_H
#define AP_PROJECT_BULLET_H

#include <memory>
#include "Ship.h"

namespace GameLogic{

    /** Class to represent all bullet types in game.
     * Class to represent all bullet types in game.
     */
    class Bullet: public Entity {
    private:

    public:
        /** Constructor for Bullet class.
         * Constructor for Bullet class.
         * @param position the starting position of the bullet
         * @param width the width of the bullet.
         * @param height the height of the bullet.
         */
        Bullet(const pair<int, int> &position, double width = 64, double height = 64);

        ~Bullet();

        /** Virtual function determines what happens when the bullet hits an Entity.
         * Function determines what happens when the bullet hits an Entity. What exactly happens depends on
         * the type of bullet and the type of Entity.
         * @param hitEntity Shared_ptr to the Entity that was hit.
         */
        virtual void hit(shared_ptr<Entity> hitEntity);

        /** Moves the bullet up or down according to speed.
         * Moves the bullet up or down according to speed.
         */
        void move();
    };
}



#endif //AP_PROJECT_BULLET_H
