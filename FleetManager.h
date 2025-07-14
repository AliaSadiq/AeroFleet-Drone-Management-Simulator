#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include <vector>
#include "Drone.h"

class FleetManager {
private:
    std::vector<Drone*> fleet;

public:
    ~FleetManager();                                      
    void addDrone(Drone* drone);                          
    void displayAll() const;                              
    Drone* findDroneById(const std::string& id);          
    bool removeDroneById(const std::string& id);         

    void saveToFile(const std::string& filename) const; 
    void loadFromFile(const std::string& filename);       
};

#endif
