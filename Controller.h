#ifndef AP_PROJECT_CONTROLLER_H
#define AP_PROJECT_CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "./SFML/Include/Level.h"


using namespace std;

/** Controller class.
 * This class will handle all input of the game. Works on the singleton priciple
 * so only one controller is always active.
 */
class Controller {
private:
    static shared_ptr<Controller> instance;

    shared_ptr<sf::RenderWindow> window;
    shared_ptr<GameSFML::Level> currentLevel;

    int levelCount = 1;
    int totalLevels = 2;

    /** Default private controller so no new instances can be created.
     * Default private controller so no new instances can be created.
     */
    Controller() = default;;
public:

    /** Function to get the controller instance.
     * Will return the controller instance if one already exists, if not it will create one.
     * @return The controller instance
     */
    static shared_ptr<Controller> getInstance();

    /** Setter for the current level in the game.
     * Setter for the current level in the game so the controller knows which entities to affect.
     * @param newLevel The new current level.
     */
    void setCurrentLevel(shared_ptr<GameSFML::Level> newLevel);

    /** Setter for the current game window.
     * Setter for the current game window so the controller knows where to get it's input from.
     * @param window The current game window.
     */
    void setWindow(shared_ptr<sf::RenderWindow> window);

    /** Main function to handle input.
     * Function will handle all input given to the game window and decide what to do with it,
     * with exception of closing the window using the window's own close button.
     */
    void handleInput();

    /// Initialize a new level in the game
    /**
     * Function initializes a new level by calling the Level Parser
     * @param levelFile the name of the json file of the new level
     */
    void initializeLevel(int levelNumber);

    shared_ptr<GameSFML::Level> &getCurrentLevel();
};


#endif //AP_PROJECT_CONTROLLER_H
