#ifndef AP_PROJECT_DOUBLESHOTENEMY_H
#define AP_PROJECT_DOUBLESHOTENEMY_H

#include "BasicEnemy.h"

namespace GameLogic{

    /** Class to represent the DoubleShotEnemy.
     * Class to represent the DoubleShotEnemy, a variant on the basic enemy that requires 2 shots to kill.
     */
    class DoubleShotEnemy : public BasicEnemy {
        private:

        public:
        /** Constructor of the DoubleShotEnemy.
         * Constructor of the DoubleShotEnemy.
         * @param position The position of the enemy in the grid
         * @param width The width of the enemy
         * @param height The height of the enemy
         */
        DoubleShotEnemy(const pair<int, int> &position, double width, double height);
    };
}




#endif //AP_PROJECT_DOUBLESHOTENEMY_H
