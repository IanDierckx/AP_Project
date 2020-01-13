#ifndef AP_PROJECT_ENTITY_H
#define AP_PROJECT_ENTITY_H

#include <map>

using namespace std;

namespace GameLogic{

    /// Base Entity class
    /***
     * Base entity class, most classes will be derived from this
     */
    class Entity {
    private:
        pair<int,int> position;

        double width;

        double height;

        string type;

        int speed{};
    protected:
        /// Funtion to set the type of the Entity
        /***
         * Function to set the type of the entity. The type is used to quickly discern what derived class the entity is
         * @param type The type this function will set.
         */
        void setType(string type);
    public:
        /// Constructor of Entity
        /***
         * Constructor of Entity
         * @param position The position of the entity in the grid
         * @param width The width of the entity
         * @param height The height of the entity
         */
        Entity(const pair<int,int> &position, double width, double height);

        /// Function to return the x coordinate
        /***
         * Function to get the x position in the grid
         * @return Integer value of the x coordinate of the entity in the grid
         */
        int getX();

        /// Function to return the y coordinate
        /***
         * Function to get the y position in the grid
         * @return Integer value of the y coordinate of the entity in the grid
         */
        int getY();

        /// Function that returns the type
        /***
         * Function that returns the type of Entity (e.g. Player)
         * @return The type of entity
         */
        string getType();

        /// Function to set the x coordinate
        /***
         * Function that sets the x coordinate in the grid
         * @param x the new x coordinate
         */
        void setX(int x);

        /// Function to set the y coordinate
        /***
         * Function that sets the y coordinate in the grid
         * @param x the new y coordinate
         */
        void setY(int y);

        /// Function that sets the entity's speed
        /***
         * Function that sets the speed of the entity
         * @param speed the entity's speed
         */
        void setSpeed(int speed);

        /// Function that gets the entity's speed
        /***
         * Function that returns the speed of the entity
         * @return Integer value of the speed of the entity
         */
        int getSpeed();
    };
}


#endif //AP_PROJECT_ENTITY_H
