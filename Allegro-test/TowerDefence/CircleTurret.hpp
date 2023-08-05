#ifndef CircleTurret_hpp
#define CircleTurret_hpp

#include "Turret.hpp"

class CircleTurret : public Turret {
public:
    static const int Price;
    CircleTurret(float x, float y);
    void CreateBullet() override;
    std::string getname() const override;
    bool spell_effect;
};
#endif // PLUGGUNTURRET_HPP
