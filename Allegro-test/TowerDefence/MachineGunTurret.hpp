#ifndef MACHINEGUNTUR_HPP
#define MACHINEGUNTUR_HPP
#include "Turret.hpp"

class MachineGunTurret : public Turret {
public:
    static const int Price;
    MachineGunTurret(float x, float y);
    void CreateBullet() override;
    std::string getname()const override;
};
#endif // PLUGGUNTURRET_HPP

