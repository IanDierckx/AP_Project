#include <memory>

#include <memory>

#include <fstream>
#include <iostream>
#include <utility>
#include "../Include/GameLogic/LevelParser.h"

namespace GameLogic{

    /// Constructor of the parser class
    LevelParser::LevelParser(const string &levelFile, GameSFML::window_ptr window) : window(std::move(window)){
        // read a JSON file
        std::ifstream file ("./Levels/"+levelFile);
        file >> imported_json;
    }

    /** The actual parsing function.
     * Function parses the json file that was imported in the constructor
     * @return Shared pointer to the created Level
     */
    shared_ptr<GameSFML::Level> LevelParser::parseJson() {
        shared_ptr<GameSFML::Level> level = make_shared<GameSFML::Level>(GameSFML::Level(window));

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
                shared_ptr<GameSFML::BasicEnemy> newEnemy = make_shared<GameSFML::BasicEnemy>(make_pair(posY,posX), 64, 50,
                        "BasicEnemy.png", window);
                level->addEnemyShip(newEnemy);
                level->addEntityToGrid(newEnemy);
            }
        }

        level->setPlayer(make_shared<GameSFML::Player>(make_pair(6,4), 50, 50, "Player.png", window));
        level->addEntityToGrid(level->getPlayer());

        return level;
    }

}

