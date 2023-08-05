#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Plug_Explosion_sfx.hpp"
#include <iostream>
const int MachineGunTurret::Price = 80;
MachineGunTurret::MachineGunTurret(float x, float y) :
    
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 350, Price, 1) {
    shifter=false;
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    
}
void MachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    arr[0]=new MachineBullet(Position + normalized * 36, diff, rotation, this);
    getPlayScene()->BulletGroup->AddNewObject(arr[0]);
    if(spellef){
        std::cout << "true" << std::endl;
        arr[0]->spell();
    }
    getPlayScene()->EffectGroup->AddNewObject(new PlugExplosion(Position.x + normalized.x * 36, Position.y + normalized.y * 36));
    AudioHelper::PlayAudio("gun.wav");
    
}
std::string MachineGunTurret::getname()const{
    return "MachineGunTurret";
}


