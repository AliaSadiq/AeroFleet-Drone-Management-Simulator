#ifndef ATTACKDRONE_H
#define ATTACKDRONE_H

#include "Drone.h"

class AttackDrone : public Drone {
public:
    AttackDrone(std::string id, std::string model);
    float getBatteryUsagePerMove() const override;
    std::string toCSV() const override;
    std::string getType() const override;
};

#endif
