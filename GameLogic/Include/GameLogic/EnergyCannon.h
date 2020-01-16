#ifndef AP_PROJECT_ENERGYCANNON_H
#define AP_PROJECT_ENERGYCANNON_H

#include "Entity.h"

namespace GameLogic{
    /** Class that represents the cannons used for shooting down enemies.
     * Class that represents the cannons used for shooting down enemies.
     */
    class EnergyCannon : public Entity {
        private:
            int timeNotUsed = 0;

            int shotDelay = 0;

        protected:
            int remainingBullets = 8;

        public:
            /** Constructor for the energy cannons.
             * Constructor for the energy cannons.
             * @param position The position in the grid of the cannon.
             * @param width The width of the cannon.
             * @param height The height of the cannon.
             */
            EnergyCannon(const pair<int, int> &position, double width, double height);

            /** Shoots the cannon.
             * If the cannon has enough bullets it return that is shoots and resets time not used to 0,
             * else it returns false.
             * @return Whether the cannon shoots or not.
             */
            bool shoot();

            /** Reloads the cannon if not used for some time.
             * Reloads the cannon if not used for some time. Returns true if able to reload.
             * @return True is able to reload.
             */
            bool autoReload();

            /** Reload the cannon.
             * Reload the cannon. Returns whether the reload was possible or not.
             * @return True if the reload was possible.
             */
            bool reload();

            /** Lowers the shotDelay by 1.
             * Lowers the shotDelay by 1.
             */
            void lowerDelay();

            /** Increases timeNotUsed by 1.
             * Increases timeNotUsed by 1.
             */
            void increaseTimeNotUsed();
    };
}




#endif //AP_PROJECT_ENERGYCANNON_H
