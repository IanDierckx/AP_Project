//
// Created by Ian on 12/4/2019.
//

#include "Entity.h"

Entity::Entity(const pair<int,int> &position) : position(position), type("Basic"), speed(0) {}

int Entity::getX() {
    return position.first;
}

int Entity::getY() {
    return position.second;
}

void Entity::setType(string type) {
    this->type = type;
}

string Entity::getType() {
    return type;
}

void Entity::setX(int x) {
    position.first = x;
}

void Entity::setY(int y) {
    position.second = y;
}

void Entity::setSpeed(int speed) {
    this->speed = speed;
}

int Entity::getSpeed() {
    return speed;
}



