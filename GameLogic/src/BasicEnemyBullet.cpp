#include "../Include/GameLogic/BasicEnemyBullet.h"
#include "../Include/GameLogic/Player.h"

GameLogic::BasicEnemyBullet::BasicEnemyBullet(const pair<int, int> &position, double width, double height) : Bullet(
        position, width, height) {}

void GameLogic::BasicEnemyBullet::hit(shared_ptr<GameLogic::Entity> hitEntity) {
    if (hitEntity->getType() == "Player") {
        auto ship = dynamic_pointer_cast<Ship>(hitEntity);
        auto player = dynamic_pointer_cast<Player>(ship);
        player->setHealth(player->getHealth()-1);
        if (player->getHealth() == 0) {
            player->setDestroyed(true);
        }
    }
}
