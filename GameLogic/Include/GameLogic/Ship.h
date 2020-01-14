//
// Created by Ian on 12/5/2019.
//

#ifndef AP_PROJECT_SHIP_H
#define AP_PROJECT_SHIP_H

#include <map>
#include <vector>
#include "Entity.h"

using namespace std;

namespace GameLogic{
    class Ship : public Entity{
    private:
        int health{};
    public:
        Ship(const pair<int,int> &position, double width, double height, int health = 1, double speed = 1);

        virtual void move();

        virtual void draw();

        int getHealth() const;

        void setHealth(int health);
    };

}



#endif //AP_PROJECT_SHIP_H
