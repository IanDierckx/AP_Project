#include <cmath>
#include "../Include/GameLogic/LogicUtils.h"

namespace GameLogic{

    /** Checks whether an int and a double are (close to) equal.
     * Checks whether an int and a double are equal to each other within a specified rounding error
     * @param dbl The double that needs checking
     * @param i The int that needs checking
     * @param rounding The rounding error that is allowed
     * @return Boolean that is true is they are equal
     */
    bool isDoubleEqualToInt(double dbl, int i, double rounding){
        return std::abs(dbl - (double)i) < rounding;
    }
}