//
// Created by student on 15.01.20.
//

#ifndef AP_PROJECT_BASICENEMYBULLET_H
#define AP_PROJECT_BASICENEMYBULLET_H

#include "Bullet.h"

namespace GameLogic{
    class BasicEnemyBullet : Bullet {
    private:

    public:
        BasicEnemyBullet(const pair<int, int> &position, double width, double height);

        void hit(shared_ptr<Entity> hitEntity) override;
    };
}



#endif //AP_PROJECT_BASICENEMYBULLET_H
