//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_PLAYERSHIP_H
#define AP_PROJECT_PLAYERSHIP_H


#include "Ship.h"

namespace GameLogic{
    class Player : public Ship {
    private:

    public:
        /// Constructor for the Player
        /***
         * The constructor for the Player. Sets the Entity type to Player and
         * sets the speed to 0.01 (speed might need balancing).
         * @param position The position of the player in the grid
         * @param width The width of the player
         * @param height The height of the player
         */
        explicit Player(const pair<int, int> &position, double width, double height);

        /// Moves the player left
        /***
         * Function moves the player left by decreasing the x value in position and movingX. Checks if player not
         * at the edge of the screen before moving.
         */
        void moveLeft();

        void moveRight();
    };
}



#endif //AP_PROJECT_PLAYERSHIP_H
