//
// Created by student on 12.12.19.
//

#include "../Include/Game.h"

namespace GameSFML{
    GameSFML::Game::Game(const string &title) {
        sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
        window = make_shared<sf::RenderWindow>(sf::VideoMode(900, 600), title,
                                                 sf::Style::Titlebar | sf::Style::Close);

    }

    void Game::run() {

        window->display();
    }
}