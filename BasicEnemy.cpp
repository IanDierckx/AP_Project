//
// Created by Ian on 12/9/2019.
//

#include "BasicEnemy.h"

void BasicEnemy::move(vector<vector<pair<bool, Entity *>>> &grid) {
    grid[getY()][getX()].first = false;
    grid[getY()][getX()].second = nullptr;
    if ((getX() == 0 and getSpeed() < 0) or (getX() == 8 and getSpeed() > 0)) {
        setY(getY()+1);
        setSpeed(-getSpeed());
    } else {
        setX(getX()+getSpeed());
    }
    grid[getY()][getX()].first = true;
    grid[getY()][getX()].second = this;
}

BasicEnemy::BasicEnemy(const pair<int, int> &position) : Ship(position) {
    setSpeed(1);
    setType("BasicEnemy");
    setHealth(1);
}

