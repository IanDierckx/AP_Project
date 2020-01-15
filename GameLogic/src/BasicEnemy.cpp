#include "../Include/GameLogic/BasicEnemy.h"
#include "../Include/GameLogic/Transformation.h"
#include "../Include/GameLogic/LogicUtils.h"


namespace GameLogic{

    /** Function that moves the Basic Enemy.
     * Function that moves the Basic Enemy to it's next position in the grid and updates movingX and movingY.
     * The Basic Enemy moves from left to right, then lowers a row before moving from right to left.
     * It then lowers a row again before moving from left to right again.
     */
    void BasicEnemy::move() {
        auto transf = Transformation::getInstance();
        if (isDoubleEqualToInt(getMovingX(),getX()) and isDoubleEqualToInt(getMovingY(), getY())) {
            if ((getX() == 0 and getSpeed() < 0) or (getX() == 8 and getSpeed() > 0)) {
                if (transf->isInGrid(make_pair(getY()+1, getX()))) {
                    setY(getY()+1);
                    setSpeed(-getSpeed());
                }
            } else {
                if (transf->isInGrid(make_pair(getY(), getX() + getSpeed()))) {
                    if (getSpeed() > 0) {
                        setX(getX()+1);
                    } else {
                        setX(getX()-1);
                    }
                }
            }
        }
        if (getMovingY() < (double)getY() and !isDoubleEqualToInt(getMovingY(),getY())) {
            if (getSpeed() < 0) {
                addMovingY(-getSpeed());
            } else {
                addMovingY(getSpeed());
            }
        } else {
            addMovingX(getSpeed());
        }
    }

    /** Constructor of Basic Enemy.
     * The constructor of the GameLogic version of the Basic Enemy class. Sets the type to BasicEnemy and gives it health and speed of 1.
     * @param position The position of the basic enemy in the grid
     * @param width The width of the basic enemy
     * @param height The height of the basic enemy
     */
    BasicEnemy::BasicEnemy(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setSpeed(0.1);
        setType("BasicEnemy");
        setHealth(1);
        shootDelay = generateShootInterval();
    }

    bool BasicEnemy::canShoot() {
        if (shootDelay == 0) {
            shootDelay = generateShootInterval();
            return true;
        } else {
            shootDelay--;
            return false;
        }
    }
}



