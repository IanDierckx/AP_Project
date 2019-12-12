//
// Created by Ian on 12/9/2019.
//

#ifndef AP_PROJECT_BASICENEMY_H
#define AP_PROJECT_BASICENEMY_H


#include <vector>
#include "Ship.h"

namespace GameLogic{
    class BasicEnemy : public Ship {
    private:

    public:
        explicit BasicEnemy(const pair<int, int> &position);

        void move() override;
    };
}




#endif //AP_PROJECT_BASICENEMY_H
