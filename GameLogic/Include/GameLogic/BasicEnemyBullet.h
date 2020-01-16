#ifndef AP_PROJECT_BASICENEMYBULLET_H
#define AP_PROJECT_BASICENEMYBULLET_H

#include "Bullet.h"

namespace GameLogic{

    /** GameLogic version of BasicEnemyBullet.
     * GameLogic version of BasicEnemyBullet.
     */
    class BasicEnemyBullet : public Bullet {
    private:

    public:
        /** Constructor for the Game Logic version of BasicEnemyBullet.
         * Constructor for the Game Logic version of BasicEnemyBullet.
         * @param position the starting position of the bullet
         * @param width the width of the bullet.
         * @param height the height of the bullet.
         */
        BasicEnemyBullet(const pair<int, int> &position, double width, double height);

//        void hit(shared_ptr<Entity> hitEntity) override;

        /** Handles what happens if the bullet collides with another entity.
         * Handles what happens if the bullet collides with another entity.
         * @param otherEntity the other entity it collides with.
         */
        void handleCollision(const shared_ptr<Entity> &otherEntity) override;
    };
}



#endif //AP_PROJECT_BASICENEMYBULLET_H
