#include "../Include/GameLogic/Player.h"
#include "../Include/GameLogic/LogicUtils.h"


namespace GameLogic{

    /** Constructor for the Player.
     * The constructor for the Player. Sets the Entity type to Player and
     * sets the speed to 0.01 (speed might need balancing).
     * @param position The position of the player in the grid
     * @param width The width of the player
     * @param height The height of the player
     */
    Player::Player(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setType("Player");
        setSpeed(0.01);
        setHealth(5);
    }

    /** Moves the player left.
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

    /** Moves the player right.
     * Function moves the player right by increasing the x value in position and movingX. Checks if player not
     * at the edge of the screen before moving.
     */
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

    /** Checks if player is destroyed.
     * Checks if player is destroyed. Which usually ends in game over.
     * @return Returns true if player is destroyed.
     */
    bool Player::isDestroyed() const {
        return destroyed;
    }

    /** Sets whether or not the player is destroyed.
     * Sets whether or not the player is destroyed.
     * @param destroyed True if the player is destroyed, false if not (for example if the player
     * gets another life from an upgrade).
     */
    void Player::setDestroyed(bool destroyed) {
        Player::destroyed = destroyed;
    }
}


