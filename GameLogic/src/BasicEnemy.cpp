//
// Created by Ian on 12/9/2019.
//

#include "../Include/GameLogic/BasicEnemy.h"
#include "../Include/GameLogic/Transformation.h"

namespace GameLogic{
    void BasicEnemy::move() {
        auto transf = Transformation::getInstance();
        if ((getX() == 0 and getSpeed() < 0) or (getX() == 8 and getSpeed() > 0)) {
            if (transf->isInGrid(make_pair(getY()+1, getX()))) {
                setY(getY()+1);
                setSpeed(-getSpeed());
            }
        } else {
            if (transf->isInGrid(make_pair(getY(), getX() + getSpeed()))) {
                setX(getX() + getSpeed());
            }
        }
    }

    BasicEnemy::BasicEnemy(const pair<int, int> &position) : Ship(position) {
        setSpeed(1);
        setType("BasicEnemy");
        setHealth(1);
    }
}



