#include <iostream>
#include "SFML/Include/Game.h"
#include "GameLogic/Include/GameLogic/Transformation.h"
#include "Controller.h"
#include "GameLogic/Include/GameLogic/Stopwatch.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
GameLogic::Stopwatch* GameLogic::Stopwatch::instance = nullptr;
shared_ptr<GameLogic::Transformation> GameLogic::Transformation::instance = nullptr;
Controller* Controller::instance = nullptr;

/** The main function
 *  Here is where the program starts
 */
int main() {
    GameSFML::Game game = GameSFML::Game();
    game.run();
    return 0;
}