//
// Created by student on 12.12.19.
//

#include "../Include/Game.h"

using namespace sf;

namespace GameSFML{
    GameSFML::Game::Game(const string &title) {
        VideoMode videoMode = VideoMode::getDesktopMode();
        window = make_shared<RenderWindow>(VideoMode(900, 600), title,
                                                 Style::Titlebar | Style::Close);
        initializeLevel("testLevel.json");
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
                break;
            }
            if (currentLevel.gameOver()) {
                if (Keyboard::isKeyPressed(Keyboard::Return)) {
                    window->close();
                   }
            } else {
                if (watch->getTimePassed()>=tick) {
                    currentLevel.update();
                    watch->reset();
                }
            }
        }
        window->clear(sf::Color::White);
        window->display();
    }
}