//
// Created by student on 18.12.19.
//

#include "../Include/GameLogic/Transformation.h"

GameLogic::Transformation::Transformation()
    :screenWidth(0),
    screenHeight(0),
    xMin(0),
    xMax(9),
    yMin(0),
    yMax(7){}

/** Function to get the transformation instance.
 * Will return the transformation instance if one already exists, if not it will create one.
 * @return The transformation instance
 */
shared_ptr<GameLogic::Transformation> GameLogic::Transformation::getInstance() {
    if (!instance)
        instance = shared_ptr<Transformation>(new Transformation);
    return instance;
}

/** Set the screen size used in calculating the correct screen coordinates.
 * Set the screen size used in calculating the correct screen coordinates.
 * @param width the width of the screen.
 * @param height the height of the screen.
 */
void GameLogic::Transformation::setScreenSize(unsigned int width, unsigned int height) {
    screenWidth = width;
    screenHeight = height;
}

/** Setter for the minimum value of the x value of the grid.
 * Setter for the minimum value of the x value of the grid. Used if you want to change the grid mid game.
 * @param xMin the new x minimum.
 */
void GameLogic::Transformation::setXMin(int xMin) {
    Transformation::xMin = xMin;
}

/** Setter for the maximum value of the x value of the grid.
 * Setter for the maximum value of the x value of the grid. Used if you want to change the grid mid game.
 * @param xMin the new x maximum.
 */
void GameLogic::Transformation::setXMax(int xMax) {
    Transformation::xMax = xMax;
}

/** Setter for the minimum value of the y value of the grid.
 * Setter for the minimum value of the y value of the grid. Used if you want to change the grid mid game.
 * @param xMin the new y minimum.
 */
void GameLogic::Transformation::setYMin(int yMin) {
    Transformation::yMin = yMin;
}

/** Setter for the maximum value of the y value of the grid.
 * Setter for the maximum value of the y value of the grid. Used if you want to change the grid mid game.
 * @param xMin the new y maximum.
 */
void GameLogic::Transformation::setYMax(int yMax) {
    Transformation::yMax = yMax;
}

//pair<int, int> GameLogic::Transformation::convertToGrid(double screenX, double screenY) {
//    pair<double, double> scaleFactor = getScaleFactor();
//    int gridX = (scaleFactor.second*screenX) - (screenWidth/2.0)+74;
//    int gridY = -scaleFactor.first*screenY + screenHeight/2.0+5;
//    return make_pair(gridY, gridX);
//}

/** Function to convert grid position (or between 2 grid positions) to screen coordinates.
 * Function to convert grid position (or between 2 grid positions) to screen coordinates.
 * @param X the x value of the position you want to convert
 * @param Y the y value of the position you want to convert
 * @return the calculated screen position
 */
pair<double, double> GameLogic::Transformation::convertToScreen(double X, double Y) {
    double screenX = (X+1 - xMin)/(xMax-xMin)*screenWidth;
    double screenY = (Y+1 - yMin)/(yMax-yMin)*screenHeight;
    return make_pair(screenX, screenY);
}

//pair<double, double> GameLogic::Transformation::getScaleFactor() {
//    double xRange = xMax - xMin;
//    double yRange = yMax - yMin;
//    return make_pair(yRange, xRange);
//}

/** Function checks whether a position is a valid grid position.
 * Checks whether the recieved x and y values are between the grid's max and min.
 * @param pos The position to check
 * @return Boolean that is true when it's a valid position.
 */
bool GameLogic::Transformation::isInGrid(pair<int, int> pos) {
    bool yCheck = pos.first <= yMax && pos.first >= yMin;
    bool xCheck = pos.second <= xMax && pos.second >= xMin;
    return yCheck && xCheck;
}
