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

shared_ptr<GameLogic::Transformation> GameLogic::Transformation::getInstance() {
    if (!instance)
        instance = shared_ptr<Transformation>(new Transformation);
    return instance;
}

void GameLogic::Transformation::setScreenSize(unsigned int width, unsigned int height) {
    screenWidth = width;
    screenHeight = height;
    return;
}

void GameLogic::Transformation::setXMin(int xMin) {
    Transformation::xMin = xMin;
}

void GameLogic::Transformation::setXMax(int xMax) {
    Transformation::xMax = xMax;
}

void GameLogic::Transformation::setYMin(int yMin) {
    Transformation::yMin = yMin;
}

void GameLogic::Transformation::setYMax(int yMax) {
    Transformation::yMax = yMax;
}

pair<int, int> GameLogic::Transformation::convertToGrid(double screenX, double screenY) {
    pair<double, double> scaleFactor = getScaleFactor();
    int gridX = scaleFactor.second*screenX - screenWidth/2.0;
    int gridY = -scaleFactor.first*screenY + screenHeight/2.0;
    return make_pair(gridY, gridX);
}

pair<double, double> GameLogic::Transformation::convertToScreen(int gridX, int gridY) {
//    pair<double, double> scaleFactor = getScaleFactor();
//    double screenY = -(gridY+scaleFactor.first/2)/scaleFactor.first*screenHeight;
//    double screenX = (gridX+scaleFactor.second/2)/scaleFactor.second*screenWidth;
    double screenX = static_cast<double>(gridX - xMin)/(xMax-xMin)*screenWidth+((screenWidth/100)*5);
    double screenY = static_cast<double>(gridY - yMin)/(yMax-yMin)*screenHeight;
    return make_pair(screenX, screenY);
}

pair<double, double> GameLogic::Transformation::getScaleFactor() {
    double xRange = xMax - xMin;
    double yRange = yMax - yMin;
    return make_pair(yRange, xRange);
}

bool GameLogic::Transformation::isInGrid(pair<int, int> pos) {
    bool yCheck = pos.first <= yMax && pos.first >= yMin;
    bool xCheck = pos.second <= xMax && pos.second >= xMin;
    return yCheck && xCheck;
}