#ifndef MACHINEGUNTUR2_HPP
#define MACHINEGUNTUR2_HPP
#include "Turret.hpp"

class MachineGunTurretv2 : public Turret {
public:
    static const int Price;
    MachineGunTurretv2(float x, float y);
    void CreateBullet() override;
    std::string getname() const override;
    
};
#endif // PLUGGUNTURRET_HPP


