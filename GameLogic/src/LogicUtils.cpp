//
// Created by student on 14.01.20.
//

#include <cmath>
#include "../Include/GameLogic/LogicUtils.h"

namespace GameLogic{
    bool isDoubleEqualToInt(double dbl, int i, double rounding){
        return std::abs(dbl - (double)i) < rounding;
    }
}