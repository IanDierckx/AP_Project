//
// Created by Ian on 12/9/2019.
//

#include "../Include/GameLogic/BasicEnemy.h"
#include "../Include/GameLogic/Transformation.h"

namespace GameLogic{

    /// Function that moves the Basic Enemy
    /***
     * Function that moves the Basic Enemy to it's next position in the grid. The Basic Enemy moves from left to right,
     * then lowers a row before moving from right to left. It then lowers a row again before moving from left to right again.
     */
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

    /// Constructor of Basic Enemy
    /***
     * The constructor of the GameLogic version of the Basic Enemy class. Sets the type to BasicEnemy and gives it health and speed of 1.
     * @param position The position of the basic enemy in the grid
     * @param width The width of the basic enemy
     * @param height The height of the basic enemy
     */
    BasicEnemy::BasicEnemy(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setSpeed(1);
        setType("BasicEnemy");
        setHealth(1);
    }
}



