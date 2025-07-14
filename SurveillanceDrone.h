#ifndef SURVEILLANCEDRONE_H
#define SURVEILLANCEDRONE_H

#include "Drone.h"

class SurveillanceDrone : public Drone {
public:
    SurveillanceDrone(std::string id, std::string model);
    float getBatteryUsagePerMove() const override;
    std::string toCSV() const override;
    std::string getType() const override;
};

#endif
