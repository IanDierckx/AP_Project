//
// Created by student on 16.01.20.
//

#include <iostream>
#include "../Include/GameLogic/EnergyCannon.h"

namespace GameLogic{

    /** Constructor for the energy cannons.
     * Constructor for the energy cannons.
     * @param position The position in the grid of the cannon.
     * @param width The width of the cannon.
     * @param height The height of the cannon.
     */
    GameLogic::EnergyCannon::EnergyCannon(const pair<int, int> &position, double width, double height) : Entity(position,
                                                                                                                width,
                                                                                                                height) {
        setType("EnergyCannon");
    }
    /** Shoots the cannon.
     * If the cannon has enough bullets it return that is shoots and resets time not used to 0,
     * else it returns false.
     * @return Whether the cannon shoots or not.
     */
    bool GameLogic::EnergyCannon::shoot() {
        if (remainingBullets > 0 and shotDelay == 0) {
//            cout << "Boom shot cannon at " << getY() << ", " << getX() << endl;
            remainingBullets--;
            timeNotUsed = 0;
            shotDelay = shotDelayMax;
            return true;
        } else {
            return false;
        }
    }

    /** Reloads the cannon if not used for some time.
     * Reloads the cannon if not used for some time. Returns true if able to reload.
     * @return True is able to reload.
     */
    bool EnergyCannon::autoReload() {
        if (timeNotUsed >= timeNotUsedTrigger and remainingBullets < maxBullets) {
            remainingBullets++;
            timeNotUsed -= 5;
            return true;
        } else {
            return false;
        }
    }

    /** Reload the cannon.
     * Reload the cannon. Returns whether the reload was possible or not.
     * @return True if the reload was possible.
     */
    bool EnergyCannon::reload() {
        if (remainingBullets < maxBullets) {
            remainingBullets++;
            timeNotUsed = 0;
            return true;
        } else {
            return false;
        }
    }

    /** Lowers the shotDelay by 1.
     * Lowers the shotDelay by 1.
     */
    void EnergyCannon::lowerDelay() {
        if (shotDelay > 0) {
            shotDelay--;
        }
    }

    /** Increases the timeNotUsed counter by 1.
     * Increases the timeNotUsed counter by 1.
     */
    void EnergyCannon::increaseTimeNotUsed() {
        timeNotUsed++;
    }
}

