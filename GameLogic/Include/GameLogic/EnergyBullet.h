#ifndef AP_PROJECT_ENERGYBULLET_H
#define AP_PROJECT_ENERGYBULLET_H

#include "Bullet.h"

namespace GameLogic{

    class EnergyBullet : public GameLogic::Bullet {
        private:

        public:
            /** Constructor for the Game Logic version of EnergyBullet.
             * Constructor for the Game Logic version of EnergyBullet.
             * @param position the starting position of the bullet
             * @param width the width of the bullet.
             * @param height the height of the bullet.
             */
            EnergyBullet(const pair<int, int> &position, double width, double height);

            /** Handles what happens if the bullet collides with another entity.
             * Handles what happens if the bullet collides with another entity.
             * @param otherEntity the other entity it collides with.
             */
            void handleCollision(const shared_ptr<Entity> &otherEntity) override;
    };
}



#endif //AP_PROJECT_ENERGYBULLET_H
