//
// Created by student on 13.12.19.
//

#include "../Include/BasicEnemy.h"

namespace GameSFML{
    BasicEnemy::BasicEnemy(const pair<int, int> &position, const string &fileName,
             const GameSFML::window_ptr window, const shared_ptr<GameLogic::Level> &level)
            : GameLogic::BasicEnemy(position){
        string spritesPath = "./res/sprites/";
        texture.loadFromFile(spritesPath+fileName);
        sprite = Sprite(texture);
        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    }
}
