#include <utility>

#include "Controller.h"

Controller *Controller::getInstance() {
    if (!instance)
        instance = new Controller;
    return instance;
}

/// Main function to handle input
/***
 * Function will handle all input given to the game window and decide what to do with it,
 * with exception of closing the window using the window's own close button.
 */
void Controller::handleInput() {
    if (currentLevel->gameOver()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            window->close();
        }
    }
}

void Controller::setCurrentLevel(shared_ptr<GameLogic::Level> newLevel) {
    currentLevel = std::move(newLevel);
}

void Controller::setWindow(shared_ptr<sf::RenderWindow> wndw) {
    window = std::move(wndw);
}

