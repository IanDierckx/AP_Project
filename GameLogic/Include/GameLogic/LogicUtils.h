//
// Created by student on 14.01.20.
//

#ifndef AP_PROJECT_LOGICUTILS_H
#define AP_PROJECT_LOGICUTILS_H

/// File used for functions that don't belong to any specific class in the Game Logic

namespace GameLogic{

    /// Checks whether an int and a double are (close to) equal
    /***
     * Checks whether an int and a double are equal to each other within a specified rounding error
     * @param dbl The double that needs checking
     * @param i The int that needs checking
     * @param rounding The rounding error that is allowed
     * @return Boolean that is true is they are equal
     */
    bool isDoubleEqualToInt(double dbl, int i, double rounding = 0.001);
}


#endif //AP_PROJECT_LOGICUTILS_H
