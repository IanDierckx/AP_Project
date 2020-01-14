//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_PLAYERSHIP_H
#define AP_PROJECT_PLAYERSHIP_H


#include "Ship.h"

namespace GameLogic{
    class Player : public Ship {
    private:

    public:
        explicit Player(const pair<int, int> &position, double width, double height);
    };
}



#endif //AP_PROJECT_PLAYERSHIP_H
