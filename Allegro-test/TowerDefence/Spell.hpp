#ifndef SPELL_HPP
#define SPELL_HPP
#include "Turret.hpp"

class Spell : public Turret {
public:
    static const int Price;
    Spell(float x, float y);
    void CreateBullet() override;
    std::string getname() const override;
};
#endif // PLUGGUNTURRET_HPP


