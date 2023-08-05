#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "Shifter.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Plug_Explosion_sfx.hpp"
const int Shifter::Price = 0;
Shifter::Shifter(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/trans.png", "play/Shifter.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Shifter::CreateBullet() {
    
}
std::string Shifter::getname()const{
    return "Shifter";
}


