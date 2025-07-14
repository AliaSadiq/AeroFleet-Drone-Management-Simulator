#include "SurveillanceDrone.h"

SurveillanceDrone::SurveillanceDrone(std::string id, std::string model)
    : Drone(id, model) {}

float SurveillanceDrone::getBatteryUsagePerMove() const {
    return 2.0f;
}

std::string SurveillanceDrone::toCSV() const {
    return "SURV," + id + "," + model + "," +
           std::to_string(battery) + "," + std::to_string(x) + "," +
           std::to_string(y) + "," + mission;
}

std::string SurveillanceDrone::getType() const {
    return "SURV";
}
