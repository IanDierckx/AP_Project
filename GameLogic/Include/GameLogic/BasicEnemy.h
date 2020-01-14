//
// Created by Ian on 12/9/2019.
//

#ifndef AP_PROJECT_BASICENEMY_H
#define AP_PROJECT_BASICENEMY_H


#include <vector>
#include "Ship.h"

namespace GameLogic{
    /// GameLogic version of the Basic Enemy class
    /***
     * GameLogic version of the easiest, most basic enemy
     */
    class BasicEnemy : public Ship {
    private:

    public:
        /// Constructor of Basic Enemy
        /***
         * The constructor of the GameLogic version of the Basic Enemy class. Sets the type to BasicEnemy and gives it health and speed of 1.
         * @param position The position of the basic enemy in the grid
         * @param width The width of the basic enemy
         * @param height The height of the basic enemy
         */
        BasicEnemy(const pair<int, int> &position, double width, double height);

        /// Function that moves the Basic Enemy
        /***
         * Function that moves the Basic Enemy to it's next position in the grid and updates movingX and movingY.
         * The Basic Enemy moves from left to right, then lowers a row before moving from right to left.
         * It then lowers a row again before moving from left to right again.
         */
        void move() override;
    };
}




#endif //AP_PROJECT_BASICENEMY_H
