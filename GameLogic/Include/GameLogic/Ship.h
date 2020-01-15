//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H

#include <map>
#include <vector>
#include "Entity.h"

using namespace std;

namespace GameLogic{

    /** Class that represents all of the ships in game logic.
     * Class that represents all of the ships (enemies and player, even though player technically isn't a ship)
     * in game logic.
     */
    class Ship : public Entity{
    private:
        int health{};
    public:

        /** Constructor of the Ship class.
         * Constructor of the Ship class.
         * @param position position of the ship in the grid
         * @param width width of the ship
         * @param height height of the ship
         * @param health health of the ship
         * @param speed speed of the ship
         */
        Ship(const pair<int,int> &position, double width, double height, int health = 1, double speed = 1);

        /** Virtual move function in Ship.
         * Virtual move function in Ship.
         */
        virtual void move();

        /** Virtual draw function in Ship.
         * Virtual draw function in Ship.
         */
        virtual void draw();

        /** Getter for the health of the ship.
         * Getter for the health of the ship.
         * @return The integer value representing the current health of the ship.
         */
        int getHealth() const;

        /** Setter for the current health of the ship.
         * Setter for the current health of the ship.
         * @param health Integer value representing the new health of the ship.
         */
        void setHealth(int health);
    };

}



#endif //AP_PROJECT_SHIP_H
