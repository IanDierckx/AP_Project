//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/Player.h"
#include "../Include/GameLogic/LogicUtils.h"


namespace GameLogic{

    /// Constructor for the Player
    /***
     * The constructor for the Player. Sets the Entity type to Player and
     * sets the speed to 0.01 (speed might need balancing).
     * @param position The position of the player in the grid
     * @param width The width of the player
     * @param height The height of the player
     */
    Player::Player(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setType("Player");
        setSpeed(0.01);
    }

    /// Moves the player left
    /***
     * Function moves the player left by decreasing the x value in position and movingX. Checks if player not
     * at the edge of the screen before moving.
     */
    void Player::moveLeft() {
        if (getSpeed() > 0) {
            setSpeed(-getSpeed());
        }
        if (getMovingX() < 0) {
            return;
        }
        if (isDoubleEqualToInt(getMovingX(), getX())) {
            if (getX() == 0 or getMovingX() < 0) {
                return;
            } else {
                setX(getX()-1);
            }
        }
        addMovingX(getSpeed());
    }

    void Player::moveRight() {
        if (getSpeed() < 0) {
            setSpeed(-getSpeed());
        }
        if (getMovingX() > 8) {
            return;
        }
        if (isDoubleEqualToInt(getMovingX(), getX())) {
            if (getX() == 8) {
                return;
            } else {
                setX(getX()+1);
            }
        }
        addMovingX(getSpeed());
    }
}

