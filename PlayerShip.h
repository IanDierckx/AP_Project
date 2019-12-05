//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_PLAYERSHIP_H
#define AP_PROJECT_PLAYERSHIP_H


#include "Ship.h"

class PlayerShip : public Ship {
private:

public:
    PlayerShip(const pair<int, int> &position, int health, int speed);
};


#endif //AP_PROJECT_PLAYERSHIP_H
