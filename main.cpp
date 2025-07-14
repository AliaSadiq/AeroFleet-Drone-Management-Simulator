#include <iostream>
#include <iomanip>
#include "Drone.h"
#include "FleetManager.h"
#include "SurveillanceDrone.h"
#include "AttackDrone.h"
using namespace std;

int main() {
    FleetManager manager;
    int choice;
    string id, model, mission;
    int x, y;

    manager.loadFromFile("fleet.txt");

    do {
        cout << "\n==================================================\n";
        cout << "         Drone Fleet Management System\n";
        cout << "==================================================\n";
        cout << left << setw(4) << "1." << "Register New Drone\n";
        cout << left << setw(4) << "2." << "Assign Mission to Drone\n";
        cout << left << setw(4) << "3." << "Move Drone\n";
        cout << left << setw(4) << "4." << "Show All Drones\n";
        cout << left << setw(4) << "5." << "Delete Drone\n";
        cout << left << setw(4) << "6." << "Save & Exit\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter Drone ID: ";
                getline(cin, id);
                cout << "Enter Drone Model: ";
                getline(cin, model);
                cout << "Select Drone Type (1 = Surveillance, 2 = Attack, other = Basic): ";
                int type;
                cin >> type;
                cin.ignore();

                if (type == 1)
                    manager.addDrone(new SurveillanceDrone(id, model));
                else if (type == 2)
                    manager.addDrone(new AttackDrone(id, model));
                else
                    manager.addDrone(new Drone(id, model));

                cout << "Drone registered successfully.\n";
                break;

            case 2:
                cout << "Enter Drone ID: ";
                getline(cin, id);
                if (Drone* d = manager.findDroneById(id)) {
                    cout << "Enter Mission Description: ";
                    getline(cin, mission);
                    d->assignMission(mission);
                    cout << "Mission assigned successfully.\n";
                } else {
                    cout << "Drone not found.\n";
                }
                break;

            case 3:
                cout << "Enter Drone ID: ";
                getline(cin, id);
                if (Drone* d = manager.findDroneById(id)) {
                    cout << "Enter New X Coordinate: ";
                    cin >> x;
                    cout << "Enter New Y Coordinate: ";
                    cin >> y;
                    cin.ignore(); 
                    d->move(x, y);
                    cout << " Drone moved successfully.\n";
                } else {
                    cout << " Drone not found.\n";
                }
                break;

            case 4:
                manager.displayAll();
                break;

            case 5:
                cout << "Enter Drone ID to delete: ";
                getline(cin, id);
                if (manager.removeDroneById(id)) {
                    cout << " Drone deleted successfully.\n";
                } else {
                    cout << "Drone not found.\n";
                }
                break;

            case 6:
                manager.saveToFile("fleet.txt");
                cout << "Fleet data saved. Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
