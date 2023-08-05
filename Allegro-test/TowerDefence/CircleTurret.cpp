#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "CircleBullet.hpp"
#include "Group.hpp"
#include "CircleTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Plug_Explosion_sfx.hpp"
#include <iostream>
const int CircleTurret::Price = 40;
CircleTurret::CircleTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/circleturret.png", x, y, 200, Price, 1.5) {
        shifter=false;
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    spell_effect=false;
}
void CircleTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    Engine::Point temp;
    temp.x=Position.x+CollisionRadius*cos(0.0152481);
    temp.y=Position.y+CollisionRadius*sin(0.0152481);
    
    Engine::Point temp2;
    float radius=temp.x-Position.x;
    temp2.x=Position.x-radius;
    temp2.y=Position.y;
    std::cout << "temp2x: " << temp2.x << " temp2y: " << temp2.y << std::endl;
//    temp.x = Position.x;
//    temp.y= ;
    
    Bullet* bullet=new CircleBullet(Position+ normalized * 36, diff, rotation, this,0);
    arr[0]=bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet=new CircleBullet(Position+ normalized * 36, diff, rotation, this,1);
    bullet->angle=ALLEGRO_PI;
    arr[1]=bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet=new CircleBullet(Position+ normalized * 36, diff, rotation, this,2);
    bullet->angle=ALLEGRO_PI/2;
    arr[2]=bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet=new CircleBullet(Position+ normalized * 36, diff, rotation, this,3);
    bullet->angle=3*(ALLEGRO_PI/2);
    arr[3]=bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    if(spellef){
        std::cout <<"wowwwwwwwwwww"<<std::endl;
        for(int i=0;i<4;i++){
            arr[i]->angle+=0.1;
        }
    }
   
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
}
std::string CircleTurret::getname()const{
    return "circleturret";
}


