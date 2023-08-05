#ifndef DICE_HPP
#define DICE_HPP
#include "Enemy.hpp"

class DiceEnemy : public Enemy {
public:
    
    DiceEnemy(std::string img,int x, int y);
    void OnExplode()override;
    std::string getname()override;

};
#endif // REDNORMALENEMY_HPP

