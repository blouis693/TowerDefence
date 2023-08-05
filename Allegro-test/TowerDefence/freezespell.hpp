#ifndef SPELL_HPP
#define SPELL_HPP
#include "Turret.hpp"

class FreezeSpell : public Turret {
public:
    static const int Price;
    FreezeSpell(float x, float y);
    void CreateBullet() override;
    std::string getname() const override;
};
#endif // PLUGGUNTURRET_HPP



