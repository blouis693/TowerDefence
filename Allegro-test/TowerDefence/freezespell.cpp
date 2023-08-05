#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "AudioHelper.hpp"
#include "MachineBullet.hpp"
#include "Group.hpp"
#include "freezespell.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Plug_Explosion_sfx.hpp"
#include <iostream>
const int FreezeSpell::Price = 80;
FreezeSpell::FreezeSpell(float x, float y) :
    
    Turret("play/trans.png", "play/elixir.png", x, y, 150, Price, 1) {
    shifter=false;
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    planted=false;

}
void FreezeSpell::CreateBullet() {
    
}
std::string FreezeSpell::getname() const{
    return "FreezeSpell";
}





