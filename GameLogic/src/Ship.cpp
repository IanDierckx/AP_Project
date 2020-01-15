//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/Ship.h"

namespace GameLogic{

    /** Constructor of the Ship class.
     * Constructor of the Ship class.
     * @param position position of the ship in the grid
     * @param width width of the ship
     * @param height height of the ship
     * @param health health of the ship
     * @param speed speed of the ship
     */
    Ship::Ship(const pair<int,int> &position, double width, double height, int health, double speed) :
    Entity(position, width, height), health(health) {
        setType("Ship");
        setSpeed(speed);
    }

    /** Getter for the health of the ship.
     * Getter for the health of the ship.
     * @return The integer value representing the current health of the ship.
     */
    int Ship::getHealth() const {
        return health;
    }

    /** Setter for the current health of the ship.
     * Setter for the current health of the ship.
     * @param health Integer value representing the new health of the ship.
     */
    void Ship::setHealth(int health) {
        Ship::health = health;
    }

    /** Virtual move function in Ship.
     * Virtual move function in Ship.
     */
    void Ship::move() {
        //virtual move class of base ship class
    }

    /** Virtual draw function in Ship.
     * Virtual draw function in Ship.
     */
    void Ship::draw() {
        //virtual draw function of base ship class
    }
}




