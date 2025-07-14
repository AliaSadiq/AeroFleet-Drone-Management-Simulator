#ifndef DRONE_H
#define DRONE_H

#include <string>

class Drone {
    friend class FleetManager;

protected:
    std::string id;
    std::string model;
    int battery;
    int x, y;
    std::string mission;

public:
    Drone();
    Drone(std::string id, std::string model);

    virtual void assignMission(std::string m);
    virtual void move(int newX, int newY);
    virtual void displayStatus() const;
    virtual float getBatteryUsagePerMove() const;

    virtual std::string toCSV() const;
    void fromCSV(const std::string& data);

    std::string getId() const;
    virtual std::string getType() const;

    virtual ~Drone() = default; 
};

#endif
