//
// Created by Ian on 12/5/2019.
//

#include "Ship.h"

Ship::Ship(const pair<int,int> &position, int health, int speed) : Entity(position), health(health) {
    setType("Ship");
    setSpeed(1);
}

int Ship::getHealth() const {
    return health;
}

void Ship::setHealth(int health) {
    Ship::health = health;
}

void Ship::move(vector<vector<pair<bool, Entity *>>> &grid) {
    //virtual move class of base ship class
}



