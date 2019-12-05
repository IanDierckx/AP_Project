//
// Created by Ian on 12/5/2019.
//

#include "Ship.h"

Ship::Ship(const pair<int,int> &position, int health, int speed) : Entity(position), health(health), speed(speed) {
    setType("Ship");
}
