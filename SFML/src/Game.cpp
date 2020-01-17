#include <iostream>
#include "../Include/Game.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"
#include "../../Controller.h"
#include "../../GameLogic/Include/GameLogic/Stopwatch.h"
#include "../Include/LevelParser.h"

using namespace sf;

namespace GameSFML{

    /// Constructor of the class
    /**
     * The constructor initializes the SFML window and initializes the first level of the game.
     * The Transformation singleton class gets the correct screen sizes (minus the borders of the screen)
     * @param title Gives the title of the window
     */
    GameSFML::Game::Game(const string &title) {
        window = make_shared<RenderWindow>(VideoMode(9*64+10, 7*64+10), title,
                                                 Style::Titlebar | Style::Close);
        initializeLevel(2);
        auto transf = GameLogic::Transformation::getInstance();
        transf->setScreenSize(window->getSize().x-64, window->getSize().y-64);
    }

    /// Function to run the actual game
    /**
     * Starts by getting the instance of the stopwatch class, which if this is the first time starts the clock
     * Game runs in a while loop with the condition of if the game window is still open
     * Inside the loop it checks for events and draws the game accordingly.
     */
    void Game::run() {
        GameLogic::Stopwatch *watch = GameLogic::Stopwatch::getInstance();
        Controller *controller = Controller::getInstance();
        controller->setCurrentLevel(currentLevel);
        controller->setWindow(window);
        double tick = 0.08;

        sf::Font MyFont;
        if (!MyFont.loadFromFile("SFML/res/fonts/ArcadeClassic.ttf"))
        {
            // Error...
        }
        sf::Text gameOver("Game Over", MyFont, 50);
        gameOver.setOrigin(gameOver.getLocalBounds().width/2, gameOver.getLocalBounds().height/2);
        gameOver.setPosition(window->getSize().x/2, window->getSize().y/2);

        while (window->isOpen()) {
            Event event{};

            while (window->pollEvent(event)) {
                if (event.type == Event::EventType::Closed) {
                    window->close();
                }
                break;
            }
            controller->handleInput();
            if (not currentLevel->gameOver()) {
                if (watch->getTimePassed()>=tick) {
                    currentLevel->update();
                    watch->reset();
                }
                window->clear(sf::Color::Black);
                currentLevel->draw();
            } else {
                window->draw(gameOver);
            }
            window->display();
        }

    }

    /// Initialize a new level in the game
    /**
     * Function initializes a new level by calling the Level Parser
     * @param levelFile the name of the json file of the new level
     */
    void Game::initializeLevel(int levelNumber) {
        LevelParser parser = LevelParser("Level" + to_string(levelNumber) + ".json", window);

        currentLevel = parser.parseJson();
    }
}