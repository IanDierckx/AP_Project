//
// Created by student on 12.12.19.
//

#include <iostream>
#include "../Include/Game.h"
#include "../../GameLogic/Include/GameLogic/Transformation.h"

using namespace sf;

namespace GameSFML{
    GameSFML::Game::Game(const string &title) {
        VideoMode videoMode = VideoMode::getDesktopMode();
        window = make_shared<RenderWindow>(VideoMode(700, 900), title,
                                                 Style::Titlebar | Style::Close);
        initializeLevel("testLevel.json");
        auto transf = GameLogic::Transformation::getInstance();
        transf->setScreenSize(window->getSize().x, window->getSize().y);
    }

    void Game::run() {
        GameLogic::Stopwatch *watch = GameLogic::Stopwatch::getInstance();
        double tick = 1.0/1.5;


        while (window->isOpen()) {
            Event event;

            while (window->pollEvent(event)) {
                if (event.type == Event::EventType::Closed) {
                    window->close();
                }
                if (event.type == Event::EventType::MouseButtonPressed) {
                    cout << Mouse::getPosition().x << endl;
                    cout << Mouse::getPosition().y << endl;
                }
                break;
            }
            if (currentLevel->gameOver()) {
                if (Keyboard::isKeyPressed(Keyboard::Return)) {
                    window->close();
                   }
            } else {
                if (watch->getTimePassed()>=tick) {
                    currentLevel->update();
                    currentLevel->draw();
                    watch->reset();
                }
            }

            window->clear(sf::Color::Black);
            currentLevel->draw();
            window->display();
        }

    }

    void Game::initializeLevel(string levelFile) {
        GameSFML::LevelParser parser = GameSFML::LevelParser(std::move(levelFile), window);

        currentLevel = parser.parseJson();

        currentLevel->printLevel();
    }
}