#include <iostream>
#include "../GameLogic/Include/GameLogic/Game.h"
#include "Include/Game.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
GameLogic::Stopwatch* GameLogic::Stopwatch::instance = 0;


int main() {
    GameSFML::Game game();
//    GameLogic::Game game = GameLogic::Game();
//    game.initializeLevel("./testLevel.json");
//    game.run();
    return 0;
}