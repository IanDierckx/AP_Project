#ifndef AP_PROJECT_ENTITY_H
#define AP_PROJECT_ENTITY_H

#include <map>
#include <memory>

using namespace std;

namespace GameLogic{

    /** Base Entity class
     * Base entity class, most classes will be derived from this
     */
    class Entity {
        private:
            pair<int,int> position;

            double width;

            double height;

            string type;

            double speed;

            double movingX;

            double movingY;

            bool needsRemoving = false;
        protected:

            /** Funtion to set the type of the Entity
             * Function to set the type of the entity. The type is used to quickly discern what derived class the entity is
             * @param type The type this function will set.
             */
            void setType(string type);
        public:
            /** Constructor of Entity
             * Constructor of Entity
             * @param position The position of the entity in the grid
             * @param width The width of the entity
             * @param height The height of the entity
             */
            Entity(const pair<int,int> &position, double width, double height);

            /** Function to return the x coordinate
             * Function to get the x position in the grid
             * @return Integer value of the x coordinate of the entity in the grid
             */
            int getX();

            /** Function to return the y coordinate
             * Function to get the y position in the grid
             * @return Integer value of the y coordinate of the entity in the grid
             */
            int getY();

            /** Function that returns the type
             * Function that returns the type of Entity (e.g. Player)
             * @return The type of entity
             */
            string getType();

            /** Function to set the x coordinate
             * Function that sets the x coordinate in the grid
             * @param x the new x coordinate
             */
            void setX(int x);

            /** Function to set the y coordinate
             * Function that sets the y coordinate in the grid
             * @param x the new y coordinate
             */
            void setY(int y);

            /** Function that sets the entity's speed
             * Function that sets the speed of the entity
             * @param speed the entity's speed
             */
            void setSpeed(double speed);

            /** Function that gets the entity's speed
             * Function that returns the speed of the entity
             * @return Double value of the speed of the entity
             */
            double getSpeed();

            /** Function to return the moving x coordinate
             * Function to get the x position used for fluid movement on screen
             * @return Integer value of the moving x coordinate of the entity
             */
            double getMovingX() const;

            /** Function to add to the moving x coordinate
             * Function to add to the x position used for fluid movement on screen
             * @param movingX Double value to be added (or subtracted using a negative value) to the existing
             * moving x value
             */
            void addMovingX(double addedX);

            /** Function to return the moving y coordinate
             * Function to get the y position used for fluid movement on screen
             * @return Integer value of the moving y coordinate of the entity
             */
            double getMovingY() const;

            /** Function to add to the moving y coordinate
             * Function to add to the y position used for fluid movement on screen
             * @param movingX Double value to be added (or subtracted using a negative value) to the existing
             * moving y value
             */
            void addMovingY(double addedY);

            /** Virtual draw function in Entity.
             * Virtual draw function in Entity.
             */
            virtual void draw() = 0;

            /** Checks if the entity is removable.
             * Checks the value of the removable variable.
             * @return the value of the removable variable.
             */
            bool checkIfRemovable();

            /** Makes the entity ready to be removed.
             * Sets the removable variable to true.
             */
            void remove();

            /** Gets the width of the entity.
             * Gets the width of the entity.
             * @return The width of the entity.
             */
            double getWidth() const;

            /** Gets the height of the entity.
             * Gets the height of the entity.
             * @return The height of the entity.
             */
            double getHeight() const;

            /** Virtual function for handling collision.
             * Virtual function for handling collision.
             * @param otherEntity the other entity it would collide with.
             */
            virtual void handleCollision(const shared_ptr<Entity> &otherEntity);
    };
}


#endif //AP_PROJECT_ENTITY_H
