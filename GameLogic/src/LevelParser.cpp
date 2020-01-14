#include <memory>

#include <memory>

//
// Created by Ian on 12/9/2019.
//

#include <fstream>
#include <iostream>
#include <utility>
#include "../Include/GameLogic/LevelParser.h"
#include "../Include/GameLogic/PlayerShip.h"

namespace GameSFML{
//Actual parser class methods

    LevelParser::LevelParser(const string &levelFile, window_ptr window) : window(std::move(window)){
        // read a JSON file
        std::ifstream file ("./Levels/"+levelFile);
        file >> imported_json;
    }

    shared_ptr<Level> LevelParser::parseJson() {
        shared_ptr<Level> level = make_shared<Level>(GameSFML::Level(window));

        level->setGrid_x(imported_json.at("grid_x").get<int>());
        level->setGrid_y(imported_json.at("grid_y").get<int>());

        for (int y = 0; y < level->getGrid_y(); ++y) {
            vector<pair<bool,shared_ptr<GameLogic::Entity>>> row;
            for (int x = 0; x < level->getGrid_x(); ++x) {
                row.emplace_back(false, nullptr);
            }
            level->addRow(row);
        }


        for (auto& enemy:imported_json.at("enemies")) {
            if (enemy.at("type").get<string>() == "basicEnemy") {
                auto posX = enemy.at("position")[1].get<int>();
                auto posY = enemy.at("position")[0].get<int>();
                shared_ptr<BasicEnemy> newEnemy = make_shared<BasicEnemy>(make_pair(posY,posX), 64, 50,
                        "BasicEnemy.png", window);
                level->addEnemyShip(newEnemy);
                level->addEntityToGrid(newEnemy);
            }
        }

        level->setPlayer(make_shared<GameLogic::PlayerShip>(make_pair(6,4), 50, 50));
        level->addEntityToGrid(level->getPlayer());

        return level;
    }

}

