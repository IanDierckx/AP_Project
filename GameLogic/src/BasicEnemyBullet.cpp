#include <iostream>
#include "../Include/GameLogic/BasicEnemyBullet.h"
#include "../Include/GameLogic/Player.h"

namespace GameLogic{
    GameLogic::BasicEnemyBullet::BasicEnemyBullet(const pair<int, int> &position, double width, double height) : Bullet(
            position, width, height) {
        setType("BasicEnemyBullet");
    }

//    void GameLogic::BasicEnemyBullet::hit(shared_ptr<GameLogic::Entity> hitEntity) {
//        if (hitEntity->getType() == "Player") {
//            auto ship = dynamic_pointer_cast<Ship>(hitEntity);
//            auto player = dynamic_pointer_cast<Player>(ship);
//            player->setHealth(player->getHealth()-1);
//            if (player->getHealth() == 0) {
//                player->setDestroyed(true);
//            }
//        }
//    }

    /** Handles what happens if the bullet collides with another entity.
     * Handles what happens if the bullet collides with another entity.
     * @param otherEntity the other entity it collides with.
     */
    void GameLogic::BasicEnemyBullet::handleCollision(const shared_ptr<GameLogic::Entity> &otherEntity) {
        if (otherEntity->getType() == "BasicEnemy") {
            return;
        } else if (otherEntity->getType() == "BasicEnemyBullet") {
            return;
        } else if (otherEntity->getType() == "Player") {
            cout << "Bullet hit player" << endl;
            shared_ptr<Player> player = dynamic_pointer_cast<Player>(otherEntity);
            player->setHealth(player->getHealth()-1);
            if (player->getHealth() == 0) {
                player->setDestroyed(true);
            }
            remove();
        }
    }
}

