//
// Created by student on 18.12.19.
//

#ifndef AP_PROJECT_SFML_LEVEL_H
#define AP_PROJECT_SFML_LEVEL_H

#include "BasicEnemy.h"

namespace GameSFML{


    class Level : public GameLogic::Level {
    private:
        window_ptr window;
    public:
        explicit Level(window_ptr& window);

        void draw();
    };
}



#endif //AP_PROJECT_SFML_LEVEL_H
