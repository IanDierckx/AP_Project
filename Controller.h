//
// Created by student on 14.01.20.
//

#ifndef AP_PROJECT_CONTROLLER_H
#define AP_PROJECT_CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "./GameLogic/Include/GameLogic/Level.h"

using namespace std;

/// Controller class
/***
 * This class will handle all input of the game. Works on the singleton priciple
 * so only one controller is always active.
 */
class Controller {
private:
    static Controller *instance;

    shared_ptr<sf::RenderWindow> window;
    shared_ptr<GameLogic::Level> currentLevel;

    /***
     * Default private controller so no new instances can be created
     */
    Controller() = default;;
public:
    /// Function to get the controller instance
    /***
     * Will return the controller instance if one already exists, if not it will create one.
     * @return The controller instance
     */
    static Controller *getInstance();

    void setCurrentLevel(shared_ptr<GameLogic::Level> newLevel);

    void setWindow(shared_ptr<sf::RenderWindow> window);


    /// Main function to handle input
    /***
     * Function will handle all input given to the game window and decide what to do with it,
     * with exception of closing the window using the window's own close button.
     */
    void handleInput();
};


#endif //AP_PROJECT_CONTROLLER_H