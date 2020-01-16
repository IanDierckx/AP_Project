#ifndef AP_PROJECT_BASICENEMYBULLET_H
#define AP_PROJECT_BASICENEMYBULLET_H

#include "Bullet.h"

namespace GameLogic{

    class BasicEnemyBullet : public Bullet {
    private:

    public:
        BasicEnemyBullet(const pair<int, int> &position, double width, double height);

//        void hit(shared_ptr<Entity> hitEntity) override;

        void handleCollision(shared_ptr<Entity> otherEntity);
    };
}



#endif //AP_PROJECT_BASICENEMYBULLET_H
