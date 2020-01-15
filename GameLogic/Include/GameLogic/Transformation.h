#ifndef AP_PROJECT_TRANSFORMATION_H
#define AP_PROJECT_TRANSFORMATION_H

#include <memory>

using namespace std;

namespace GameLogic{

    /** Class used to convert from the gameLogic grid to screen coordinates.
     * Class used to convert from the gameLogic grid to screen coordinates. Uses the singleton pattern.
     */
    class Transformation {
    private:

        static shared_ptr<Transformation> instance;
        unsigned int screenWidth;
        unsigned int screenHeight;

        int xMin;
        int xMax;
        int yMin;
        int yMax;

        /** Private contructor that sets up the grid size.
         * Private contructor that sets up the grid size.
         */
        Transformation();

    public:

        /** Function to get the transformation instance.
         * Will return the transformation instance if one already exists, if not it will create one.
         * @return The transformation instance
         */
        static shared_ptr<Transformation> getInstance();

        /** Set the screen size used in calculating the correct screen coordinates.
         * Set the screen size used in calculating the correct screen coordinates.
         * @param width the width of the screen.
         * @param height the height of the screen.
         */
        void setScreenSize(unsigned int width, unsigned int height);

        /** Setter for the minimum value of the x value of the grid.
         * Setter for the minimum value of the x value of the grid. Used if you want to change the grid mid game.
         * @param xMin the new x minimum.
         */
        void setXMin(int xMin);

        /** Setter for the maximum value of the x value of the grid.
         * Setter for the maximum value of the x value of the grid. Used if you want to change the grid mid game.
         * @param xMin the new x maximum.
         */
        void setXMax(int xMax);

        /** Setter for the minimum value of the y value of the grid.
         * Setter for the minimum value of the y value of the grid. Used if you want to change the grid mid game.
         * @param xMin the new y minimum.
         */
        void setYMin(int yMin);

        /** Setter for the maximum value of the y value of the grid.
         * Setter for the maximum value of the y value of the grid. Used if you want to change the grid mid game.
         * @param xMin the new y maximum.
         */
        void setYMax(int yMax);

//        pair<int, int> convertToGrid(double screenX, double screenY);

        /** Function to convert grid position (or between 2 grid positions) to screen coordinates.
         * Function to convert grid position (or between 2 grid positions) to screen coordinates.
         * @param X the x value of the position you want to convert
         * @param Y the y value of the position you want to convert
         * @return the calculated screen position
         */
        pair<double, double> convertToScreen(double X, double Y);

//        pair<double, double> getScaleFactor();

        /** Function checks whether a position is a valid grid position.
         * Checks whether the recieved x and y values are between the grid's max and min.
         * @param pos The position to check
         * @return Boolean that is true when it's a valid position.
         */
        bool isInGrid(pair<int, int> pos);
    };
}



#endif //AP_PROJECT_TRANSFORMATION_H
