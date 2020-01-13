//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/Ship.h"

namespace GameLogic{
    Ship::Ship(const pair<int,int> &position, double width, double height, int health, int speed) :
    Entity(position, width, height), health(health) {
        setType("Ship");
        setSpeed(1);
    }

    int Ship::getHealth() const {
        return health;
    }

    void Ship::setHealth(int health) {
        Ship::health = health;
    }

    void Ship::move() {
        //virtual move class of base ship class
    }

    void Ship::draw() {
        //virtual draw function of base ship class
    }
}




