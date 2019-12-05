//
// Created by Ian on 12/4/2019.
//

#include "Entity.h"

Entity::Entity(const pair<int,int> &position) : position(position), type("Basic") {}

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
