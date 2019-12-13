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

        while (window->isOpen()) {
            Event event;

            while (window->pollEvent(event)) {
                if (event.type == Event::EventType::Closed) {
                    window->close();
                }
                break;
            }
            if (watch->getTimePassed()>1) {
//                currentLevel.updateGrid();
            }
        }
        window->clear(sf::Color::White);
        window->display();
    }
}