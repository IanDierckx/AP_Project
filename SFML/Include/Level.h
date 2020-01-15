#ifndef AP_PROJECT_SFML_LEVEL_H
#define AP_PROJECT_SFML_LEVEL_H

#include "BasicEnemy.h"
#include "Player.h"

namespace GameSFML{


    class Level : public GameLogic::Level {
    private:
        window_ptr window;
    public:
        explicit Level(window_ptr& window);

        void draw();

        void update();
    };
}



#endif //AP_PROJECT_SFML_LEVEL_H
