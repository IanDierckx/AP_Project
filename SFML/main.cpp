#include <iostream>
#include "../GameLogic/Include/GameLogic/Game.h"
#include "Include/Game.h"
#include "../GameLogic/Include/GameLogic/Transformation.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
GameLogic::Stopwatch* GameLogic::Stopwatch::instance = 0;
shared_ptr<GameLogic::Transformation> GameLogic::Transformation::instance = 0;


int main() {
    GameSFML::Game game = GameSFML::Game();
    game.run();
    return 0;
}