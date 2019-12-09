//
// Created by Ian on 12/5/2019.
//

#include "PlayerShip.h"

PlayerShip::PlayerShip(const pair<int, int> &position) : Ship(position) {
    setType("Player");
}
