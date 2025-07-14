#include "Drone.h"
#include <iostream>
#include <sstream>

Drone::Drone() : id(""), model(""), battery(100), x(0), y(0), mission("None") {}

Drone::Drone(std::string id, std::string model)
    : id(id), model(model), battery(100), x(0), y(0), mission("None") {}

void Drone::assignMission(std::string m) {
    mission = m;
}

void Drone::move(int newX, int newY) {
    x = newX;
    y = newY;
    battery -= getBatteryUsagePerMove();
    if (battery < 0) battery = 0;
}

float Drone::getBatteryUsagePerMove() const {
    return 5.0f;
}

void Drone::displayStatus() const {
    std::cout << "\nDrone ID: " << id
              << "\nModel: " << model
              << "\nBattery: " << battery << "%" << (battery < 20 ? " ⚠️ Low Battery!" : "")
              << "\nLocation: (" << x << ", " << y << ")"
              << "\nMission: " << mission << "\n";
}

std::string Drone::toCSV() const {
    return "BASE," + id + "," + model + "," +
           std::to_string(battery) + "," + std::to_string(x) + "," +
           std::to_string(y) + "," + mission;
}

void Drone::fromCSV(const std::string& data) {
    std::stringstream ss(data);
    std::string type;
    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, model, ',');
    std::string token;
    getline(ss, token, ','); battery = std::stof(token);
    getline(ss, token, ','); x = std::stoi(token);
    getline(ss, token, ','); y = std::stoi(token);
    getline(ss, mission);
}

std::string Drone::getId() const {
    return id;
}

std::string Drone::getType() const {
    return "BASE";
}
