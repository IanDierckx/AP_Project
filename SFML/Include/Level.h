#ifndef AP_PROJECT_SFML_LEVEL_H
#define AP_PROJECT_SFML_LEVEL_H

#include "BasicEnemy.h"
#include "Player.h"

namespace GameSFML{

    /** SFML version of the Level class.
     * SFML version of the Level class.
     */
    class Level : public GameLogic::Level {
    private:
        window_ptr window;
    public:

        /** Constructor of the SFML version of Level.
         * Constructor of the SFML version of Level.
         * @param window the current game window.
         */
        explicit Level(window_ptr& window);

        /** Calls the draw function of all entities.
         * Calls the draw function of all entities.
         */
        void draw();

        /** Extends the GameLogic version of the update function.
         * Extends the GameLogic version of the update function by creating new bullets if necessary,
         * checking for collisions and removing removable entities.
         */
        void update() override;

        void createPlayerBullet(double y, double x) override;
    };
}



#endif //AP_PROJECT_SFML_LEVEL_H
