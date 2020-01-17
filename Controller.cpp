#include <utility>

#include "Controller.h"
#include "./SFML/Include/LevelParser.h"


/** Function to get the controller instance.
 * Will return the controller instance if one already exists, if not it will create one.
 * @return The controller instance
 */
shared_ptr<Controller> Controller::getInstance() {
    if (!instance)
        instance = shared_ptr<Controller>(new Controller);
    return instance;
}

/** Main function to handle input.
 * Function will handle all input given to the game window and decide what to do with it,
 * with exception of closing the window using the window's own close button.
 */
void Controller::handleInput() {
    if (currentLevel->gameOver()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            if (currentLevel->won()) {
                if (levelCount == totalLevels) {
                    window->close();
                } else {
                    initializeLevel(++levelCount);
                    setCurrentLevel(currentLevel);
                }
            } else {
                window->close();
            }
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentLevel->getPlayer()->moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentLevel->getPlayer()->moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            auto player = currentLevel->getPlayer();
            auto entityAbovePlayer = currentLevel->getEntityInGrid(player->getY()-1,
                    static_cast<int>(round(player->getMovingX())));
            if (entityAbovePlayer != nullptr) {
                if (entityAbovePlayer->getType() == "EnergyCannon") {
                    auto cannonAbovePlayer = dynamic_pointer_cast<GameLogic::EnergyCannon>(entityAbovePlayer);
                    if (cannonAbovePlayer->shoot()) {
                        currentLevel->createPlayerBullet(cannonAbovePlayer->getY(), cannonAbovePlayer->getX());
                    };
                }
            }
        }
    }
}

/** Setter for the current level in the game.
 * Setter for the current level in the game so the controller knows which entities to affect.
 * @param newLevel The new current level.
 */
void Controller::setCurrentLevel(shared_ptr<GameSFML::Level> newLevel) {
    currentLevel = std::move(newLevel);
}

void Controller::setWindow(shared_ptr<sf::RenderWindow> wndw) {
    window = std::move(wndw);
}

/// Initialize a new level in the game
/**
 * Function initializes a new level by calling the Level Parser
 * @param levelFile the name of the json file of the new level
 */
void Controller::initializeLevel(int levelNumber) {
    GameSFML::LevelParser parser = GameSFML::LevelParser("Level" + to_string(levelNumber) + ".json", window);

    currentLevel = parser.parseJson();
}

/** Getter for the current level.
 * Getter for the current level.
 * @return the current level.
 */
shared_ptr<GameSFML::Level> &Controller::getCurrentLevel() {
    return currentLevel;
}
