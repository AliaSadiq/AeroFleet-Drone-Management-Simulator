#include "AttackDrone.h"

AttackDrone::AttackDrone(std::string id, std::string model)
    : Drone(id, model) {}

float AttackDrone::getBatteryUsagePerMove() const {
    return 10.0f;
}

std::string AttackDrone::toCSV() const {
    return "ATTACK," + id + "," + model + "," +
           std::to_string(battery) + "," + std::to_string(x) + "," +
           std::to_string(y) + "," + mission;
}

std::string AttackDrone::getType() const {
    return "ATTACK";
}
