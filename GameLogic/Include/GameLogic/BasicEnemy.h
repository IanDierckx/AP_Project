#ifndef AP_PROJECT_BASICENEMY_H
#define AP_PROJECT_BASICENEMY_H


#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <memory>

#include "Ship.h"

/// Namespace used for the game logic (a.k.a. the module of the MVC pattern)
namespace GameLogic{

    /** GameLogic version of the Basic Enemy class.
     * GameLogic version of the easiest, most basic enemy
     */
    class BasicEnemy : public Ship {
        private:
            int shootDelay;


        public:

            /** Constructor of Basic Enemy.
             * The constructor of the GameLogic version of the Basic Enemy class. Sets the type to BasicEnemy and gives it health and speed of 1.
             * @param position The position of the basic enemy in the grid
             * @param width The width of the basic enemy
             * @param height The height of the basic enemy
             */
            BasicEnemy(const pair<int, int> &position, double width, double height);


            /** Function that moves the Basic Enemy.
             * Function that moves the Basic Enemy to it's next position in the grid and updates movingX and movingY.
             * The Basic Enemy moves from left to right, then lowers a row before moving from right to left.
             * It then lowers a row again before moving from left to right again.
             */
            void move() override;

            /** Checks if the enemy can shoot.
             * Checks if the enemy can shoot.
             * @return True if the enemy can shoot.
             */
            bool canShoot();

            /** Generates a random interval for when an enemy can shoot again.
             * Generates a random interval for when an enemy can shoot again.
             * @return the random interval between 20 and 100
             */
            int generateShootInterval();

            void handleCollision(shared_ptr<Entity> otherEntity);
    };
}




#endif //AP_PROJECT_BASICENEMY_H
