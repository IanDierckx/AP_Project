#ifndef AP_PROJECT_PLAYERSHIP_H
#define AP_PROJECT_PLAYERSHIP_H


#include "Ship.h"

namespace GameLogic{

    /** Class to represent the player.
     * Class represents the game logic version of the player
     */
    class Player : public Ship {
    private:
        bool destroyed = false;

    public:

        /** Constructor for the Player.
         * The constructor for the Player. Sets the Entity type to Player and
         * sets the speed to 0.01 (speed might need balancing).
         * @param position The position of the player in the grid
         * @param width The width of the player
         * @param height The height of the player
         */
        explicit Player(const pair<int, int> &position, double width, double height);

        /** Moves the player left.
         * Function moves the player left by decreasing the x value in position and movingX. Checks if player not
         * at the edge of the screen before moving.
         */
        void moveLeft();

        /** Moves the player right.
         * Function moves the player right by increasing the x value in position and movingX. Checks if player not
         * at the edge of the screen before moving.
         */
        void moveRight();

        /** Checks if player is destroyed.
         * Checks if player is destroyed. Which usually ends in game over.
         * @return Returns true if player is destroyed.
         */
        bool isDestroyed() const;

        /** Sets whether or not the player is destroyed.
         * Sets whether or not the player is destroyed.
         * @param destroyed True if the player is destroyed, false if not (for example if the player
         * gets another life from an upgrade).
         */
        void setDestroyed(bool destroyed);
    };
}



#endif //AP_PROJECT_PLAYERSHIP_H
