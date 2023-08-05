#include <string>
#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "DiceEnemy.hpp"
#include "RedNormalEnemy.hpp"
#include <random>
int flag=5;
int MapWidthh = 20, MapHeight = 13;
int BlockSizee = 64;
Engine::Point SpawnGridPointt = Engine::Point(-1, 0);

DiceEnemy::DiceEnemy(std::string img,int x, int y) : Enemy(img, x, y, 25, 65,4, 50) {
    // TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
    flagg=5;
}
void DiceEnemy::OnExplode(){
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
    for (int i = 0; i < 10; i++) {
        // Random add 10 dirty effects.
        getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
    }
    Enemy* enemy;
    if(this->end==true){
        std::cout << "end" << std::endl;
        return;
    }
    else std::cout << "gak" << std::endl;
    if(flagg!=0){
        getPlayScene()->EarnMoney(-50);
        auto mapp=getPlayScene()->mapDistance;
        std:: string img;
        img="play/dice-"+std::to_string(flagg)+".png";
        std::cout << img << std::endl;
        getPlayScene()->EnemyGroup->AddNewObject(enemy = new DiceEnemy(img,Position.x, Position.y));
        enemy->UpdatePath(mapp);
        flagg--;
        enemy->flagg=flagg;
    }
}
std::string DiceEnemy::getname(){
    return "Dice";
}

