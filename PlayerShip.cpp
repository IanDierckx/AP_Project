//
// Created by Ian on 12/5/2019.
//

#include "PlayerShip.h"

PlayerShip::PlayerShip(const pair<int, int> &position, int health, int speed) : Ship(position, health, speed) {
    setType("Player");
    this->setX(6);
    this->setY(4);
}
