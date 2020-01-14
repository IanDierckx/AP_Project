//
// Created by Ian on 12/5/2019.
//

#include "../Include/GameLogic/Player.h"

namespace GameLogic{
    PlayerShip::PlayerShip(const pair<int, int> &position, double width, double height) : Ship(position, width, height) {
        setType("Player");
    }
}


