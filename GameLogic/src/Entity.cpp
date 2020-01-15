#include <utility>

#include "../Include/GameLogic/Entity.h"

namespace GameLogic{

    /** Constructor of Entity
     * Constructor of Entity
     * @param position The position of the entity in the grid
     * @param width The width of the entity
     * @param height The height of the entity
     */
    Entity::Entity(const pair<int,int> &position, double width, double height)
    : position(position), width(width), height(height), type("Basic"), speed(0), movingX(position.second)
    , movingY(position.first) {}

    /** Function to return the x coordinate
     * Function to get the x position in the grid
     * @return Integer value of the x coordinate of the entity in the grid
     */
    int Entity::getX() {
        return position.second;
    }

    /** Function to return the y coordinate
     * Function to get the y position in the grid
     * @return Integer value of the y coordinate of the entity in the grid
     */
    int Entity::getY() {
        return position.first;
    }

    /** Funtion to set the type of the Entity
     * Function to set the type of the entity. The type is used to quickly discern what derived class the entity is
     * @param type The type this function will set.
     */
    void Entity::setType(string type) {
        this->type = std::move(type);
    }

    /** Function that returns the type
     * Function that returns the type of Entity (e.g. Player)
     * @return The type of entity
     */
    string Entity::getType() {
        return type;
    }

    /** Function to set the x coordinate
     * Function that sets the x coordinate in the grid
     * @param x the new x coordinate
     */
    void Entity::setX(int x) {
        position.second = x;
    }

    /** Function to set the y coordinate
     * Function that sets the y coordinate in the grid
     * @param x the new y coordinate
     */
    void Entity::setY(int y) {
        position.first = y;
    }

    /** Function that sets the entity's speed
     * Function that sets the speed of the entity
     * @param speed the entity's speed
     */
    void Entity::setSpeed(double speed) {
        this->speed = speed;
    }

    /** Function that gets the entity's speed
     * Function that returns the speed of the entity
     * @return Double value of the speed of the entity
     */
    double Entity::getSpeed() {
        return speed;
    }

    /** Function to return the moving x coordinate
     * Function to get the x position used for fluid movement on screen
     * @return Integer value of the moving x coordinate of the entity
     */
    double Entity::getMovingX() const {
        return movingX;
    }

    /** Function to add to the moving x coordinate
     * Function to add to the x position used for fluid movement on screen
     * @param movingX Double value to be added (or subtracted using a negative value) to the existing
     * moving x value
     */
    void Entity::addMovingX(double addedX) {
        Entity::movingX += addedX;
    }

    /** Function to return the moving y coordinate
     * Function to get the y position used for fluid movement on screen
     * @return Integer value of the moving y coordinate of the entity
     */
    double Entity::getMovingY() const {
        return movingY;
    }

    /** Function to add to the moving y coordinate
     * Function to add to the y position used for fluid movement on screen
     * @param movingX Double value to be added (or subtracted using a negative value) to the existing
     * moving y value
     */
    void Entity::addMovingY(double addedY) {
        Entity::movingY += addedY;
    }

    void Entity::draw() {
        ///Virtual function
    }
}



