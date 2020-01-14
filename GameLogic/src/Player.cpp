//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/Player.h"
#include "../Include/GameLogic/LogicUtils.h"


namespace GameLogic{
    Player::Player(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setType("Player");
        setSpeed(0.01);
    }

    void Player::moveLeft() {
        if (getSpeed() > 0) {
            setSpeed(-getSpeed());
        }
        if (isDoubleEqualToInt(getMovingX(), getX())) {
            if (getX() == 0) {
                return;
            } else {
                setX(getX()-1);
            }
        }
        addMovingX(getSpeed());
    }
}


