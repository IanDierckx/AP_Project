//
// Created by student on 18.12.19.
//

#ifndef AP_PROJECT_TRANSFORMATION_H
#define AP_PROJECT_TRANSFORMATION_H

#include <memory>

using namespace std;

namespace GameLogic{

    class Transformation {
        static shared_ptr<Transformation> instance;
        unsigned int screenWidth;
        unsigned int screenHeight;

        int xMin;
        int xMax;
        int yMin;
        int yMax;

        Transformation();

    public:
        static shared_ptr<Transformation> getInstance();

        void setScreenSize(unsigned int width, unsigned int height);

        void setXMin(int xMin);

        void setXMax(int xMax);

        void setYMin(int yMin);

        void setYMax(int yMax);

//        pair<int, int> convertToGrid(double screenX, double screenY);

        pair<double, double> convertToScreen(double X, double Y);

        pair<double, double> getScaleFactor();

        bool isInGrid(pair<int, int> pos);
    };
}



#endif //AP_PROJECT_TRANSFORMATION_H
