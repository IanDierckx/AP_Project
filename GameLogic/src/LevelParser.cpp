//
// Created by Ian on 12/9/2019.
//

#include <fstream>
#include <iostream>
#include "../Include/GameLogic/LevelParser.h"
#include "../Include/GameLogic/BasicEnemy.h"
#include "../Include/GameLogic/PlayerShip.h"

namespace GameLogic{
//Actual parser class methods

    LevelParser::LevelParser(string levelFile) {
        // read a JSON file
        std::ifstream file ("testLevel.json");
        file >> imported_json;
    }

    Level LevelParser::parseJson() {
        Level level = Level();

        level.setGrid_x(imported_json.at("grid_x").get<int>());
        level.setGrid_y(imported_json.at("grid_y").get<int>());

        for (int y = 0; y < level.getGrid_y(); ++y) {
            vector<pair<bool,Entity*>> row;
            for (int x = 0; x < level.getGrid_x(); ++x) {
                row.emplace_back(false, nullptr);
            }
            level.addRow(row);
        }


        for (auto& enemy:imported_json.at("enemies")) {
            if (enemy.at("type").get<string>() == "basicEnemy") {
                int posX = enemy.at("position")[1].get<int>();
                int posY = enemy.at("position")[0].get<int>();
                BasicEnemy* newEnemy = new BasicEnemy(make_pair(posY,posX));
                level.addEnemyShip(newEnemy);
                level.addEntityToGrid(newEnemy);
            }
        }

        level.setPlayer(new PlayerShip(make_pair(6,4)));
        level.addEntityToGrid(level.getPlayer());

        return level;
    }

}

