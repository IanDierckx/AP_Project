#ifndef AP_PROJECT_LEVELPARSER_H
#define AP_PROJECT_LEVELPARSER_H

#include "json.hpp"
#include "Ship.h"
#include "PlayerShip.h"

// for convenience
using json = nlohmann::json;


class Level {
private:
    vector<Ship*> enemyShips;

    vector<vector<pair<bool,Entity*>>> grid;

    int grid_x = 9;
    int grid_y = 7;

    PlayerShip* player;
public:
    const vector<Ship *> &getEnemyShips() const;

    void setEnemyShips(const vector<Ship *> &enemyShips);

    void addEnemyShip(Ship* ship);

    const vector<vector<pair<bool, Entity *>>> &getGrid() const;

    void updateGrid();

    void addRow(vector<pair<bool, Entity *>> row);

    int getGrid_x() const;

    void setGrid_x(int grid_x);

    int getGrid_y() const;

    void setGrid_y(int grid_y);

    void addEntityToGrid(Entity* entity);

    void printLevel();

    PlayerShip *getPlayer() const;

    void setPlayer(PlayerShip *player);
};

class LevelParser {
private:
    json imported_json;
public:
    explicit LevelParser(string levelFile);

    Level parseJson();
};


#endif //AP_PROJECT_LEVELPARSER_H
