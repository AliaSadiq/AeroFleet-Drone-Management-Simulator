#include "FleetManager.h"
#include "SurveillanceDrone.h"
#include "AttackDrone.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

FleetManager::~FleetManager() {
    for (Drone* d : fleet) {
        delete d;
    }
    fleet.clear();
}

void FleetManager::addDrone(Drone* drone) {
    fleet.push_back(drone);
}

void FleetManager::displayAll() const {
    if (fleet.empty()) {
        std::cout << "\n⚠️  No drones in the fleet.\n";
        return;
    }

    std::cout << "\n=========================================================================================================================================================================================================\n";
    std::cout << "| " << std::left << std::setw(9) << "ID"
              << "| " << std::setw(10) << "Type"
              << "| " << std::setw(13) << "Model"
              << "| " << std::setw(8) << "Battery"
              << "| " << std::setw(11) << "Location"
              << "| " << std::setw(15) << "Mission" << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const Drone* d : fleet) {
        std::cout << "| " << std::left << std::setw(9) << d->getId()
                  << "| " << std::setw(10) << d->getType()
                  << "| " << std::setw(13) << d->model
                  << "| " << std::setw(8) << (std::to_string(d->battery) + "%")
                  << "| " << std::setw(11) << ("(" + std::to_string(d->x) + ", " + std::to_string(d->y) + ")")
                  << "| " << std::setw(15) << d->mission << "\n";
    }

    std::cout << "=========================================================================================================================================================================================================\n";
}

Drone* FleetManager::findDroneById(const std::string& id) {
    for (Drone* d : fleet) {
        if (d->getId() == id)
            return d;
    }
    return nullptr;
}

bool FleetManager::removeDroneById(const std::string& id) {
    for (auto it = fleet.begin(); it != fleet.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            fleet.erase(it);
            return true;
        }
    }
    return false;
}

void FleetManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const Drone* d : fleet) {
        file << d->toCSV() << "\n";
    }
    file.close();
}

void FleetManager::loadFromFile(const std::string& filename) {
    for (Drone* d : fleet) delete d;
    fleet.clear();

    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        getline(ss, type, ',');

        Drone* d;
        if (type == "SURV")
            d = new SurveillanceDrone("", "");
        else if (type == "ATTACK")
            d = new AttackDrone("", "");
        else
            d = new Drone();

        d->fromCSV(line);
        fleet.push_back(d);
    }

    file.close();
}
