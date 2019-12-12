#include <utility>

#include "../Include/GameLogic/Entity.h"

namespace GameLogic{
    Entity::Entity(const pair<int,int> &position) : position(position), type("Basic"), speed(0) {}

    int Entity::getX() {
        return position.second;
    }

    int Entity::getY() {
        return position.first;
    }

    void Entity::setType(string type) {
        this->type = std::move(type);
    }

    string Entity::getType() {
        return type;
    }

    void Entity::setX(int x) {
        position.second = x;
    }

    void Entity::setY(int y) {
        position.first = y;
    }

    void Entity::setSpeed(int speed) {
        this->speed = speed;
    }

    int Entity::getSpeed() {
        return speed;
    }
}



