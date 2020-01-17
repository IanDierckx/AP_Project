#include "../Include/GameLogic/DoubleShotEnemy.h"

namespace GameLogic{

    GameLogic::DoubleShotEnemy::DoubleShotEnemy(const pair<int, int> &position, double width, double height)
            : BasicEnemy(position, width, height) {
        setType("DoubleShotEnemy");
        setHealth(2);
    }
}

