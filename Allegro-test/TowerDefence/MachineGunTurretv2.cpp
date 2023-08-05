#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurretv2.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Plug_Explosion_sfx.hpp"

const int MachineGunTurretv2::Price = 80;
MachineGunTurretv2::MachineGunTurretv2(float x, float y) :
    
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 350, Price, 2) {
    shifter=false;
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurretv2::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point normalized1 = Engine::Point(cos(Rotation - ALLEGRO_PI / 2 + 0.2), sin(Rotation - ALLEGRO_PI / 2 +0.2)).Normalize();
    Engine::Point normalized2 = Engine::Point(cos(Rotation - ALLEGRO_PI / 2 - 0.2), sin(Rotation - ALLEGRO_PI / 2 - 0.2)).Normalize();

    Engine::Point temp=Engine::Point(21,0);

    // Change bullet position to the front of the gun barrel.
    arr[0]=new MachineBullet(Position + normalized1 * 38, diff, rotation, this);
    arr[1]=new MachineBullet(Position + normalized2 * 38, diff, rotation, this);

    getPlayScene()->BulletGroup->AddNewObject(arr[0]);
    getPlayScene()->BulletGroup->AddNewObject(arr[1]);
    if(spellef){
        arr[0]->spell();
        arr[1]->spell();
    }
    //getPlayScene()->BulletGroup->AddNewObject(new MachineBullet(Position + normalized * 36, diff, rotation, this));

    getPlayScene()->EffectGroup->AddNewObject(new PlugExplosion(Position.x + normalized.x * 36, Position.y + normalized.y * 36));
    AudioHelper::PlayAudio("gun.wav");
}
std::string MachineGunTurretv2::getname ()const
{
    return "MachineGunTurret2";
}
