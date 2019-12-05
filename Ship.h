//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H

#include <map>
#include "Entity.h"

using namespace std;

class Ship : public Entity{
private:
    int health{};
    int speed{};
public:
    Ship(const pair<int,int> &position, int health, int speed);
};


#endif //AP_PROJECT_SHIP_H
