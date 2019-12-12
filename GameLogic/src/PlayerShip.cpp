//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/PlayerShip.h"

namespace GameLogic{
    PlayerShip::PlayerShip(const pair<int, int> &position) : Ship(position) {
        setType("Player");
    }
}


