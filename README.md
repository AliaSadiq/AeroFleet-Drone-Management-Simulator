# AeroFleet-Drone-Management-Simulator
# AeroFleet-Drone-Management-Simulator

A console-based drone fleet management simulation built in C++. This project uses object-oriented programming principles to allow users to register, control, and monitor a fleet of surveillance and attack drones in real time. Created as a showcase project for NASTP.

---

------------------------------------------------------------
## 🚀 Features
------------------------------------------------------------


- ✅ Register new drones (Basic, Surveillance, or Attack)
- 📡 Assign custom missions to drones
- 📍 Move drones using coordinate simulation (X, Y)
- 🪫 Battery drain based on drone type and movement
- ⚠️ Low battery warning (when battery < 20%)
- 💾 Save & load fleet data from a file (`fleet.txt`)
- 🗑️ Delete drones from fleet
- 🧠 Demonstrates Inheritance, Polymorphism, Encapsulation

---

------------------------------------------------------------
## 🧠 OOP Concepts Used
------------------------------------------------------------
| Concept         | Where It’s Used                                |
|----------------|--------------------------------------------------|
| Classes         | `Drone`, `FleetManager`, etc.                  |
| Inheritance     | `SurveillanceDrone`, `AttackDrone`              |
| Polymorphism    | Overriding `move()`, `getBatteryUsage()`        |
| Encapsulation   | Private data with public methods                |
| File Handling   | Save/load drone data using CSV-style files      |

---

------------------------------------------------------------
## 📂 Project Structure
------------------------------------------------------------
AeroFleet-Drone-Management-Simulator/
├── main.cpp                   → Main menu logic
├── Drone.h / Drone.cpp        → Base Drone class
├── SurveillanceDrone.h / .cpp → Inherited Surveillance drone
├── AttackDrone.h / .cpp       → Inherited Attack drone
├── FleetManager.h / .cpp      → Manages fleet operations
├── fleet.txt                  → Auto-saved drone data
├── README.txt or README.md    → This documentation


---

------------------------------------------------------------
## 📦 Drone Types
------------------------------------------------------------
| Drone Type        | Battery Usage per Move | Use Case             |
|------------------|------------------------|----------------------|
| `BASE`           | 5%                     | Standard operations  |
| `SURVEILLANCE`   | 2%                     | Border patrol, recon |
| `ATTACK`         | 10%                    | Strike missions      |

---

------------------------------------------------------------
## 🧪 Sample Console Output 
------------------------------------------------------------
=== Drone Fleet Management System ===
1. Register New Drone
2. Assign Mission to Drone
3. Move Drone
4. Show All Drones
5. Delete Drone
6. Save & Exit
Enter your choice: 1

Enter Drone ID: DR-001
Enter Drone Model: EyeHawk
Select Drone Type (1 = Surveillance, 2 = Attack, other = Basic): 1
Drone registered successfully.

Enter your choice: 4

Drone ID: DR-001
Model: EyeHawk
Battery: 98.0% 
Location: (0, 0)
Mission: None

---


------------------------------------------------------------
## 💾 Sample Saved File (fleet.txt)
------------------------------------------------------------
SURV,DR-001,EyeHawk,92.0,10,15,Border Patrol
ATTACK,DR-002,HammerX,70.0,20,30,Strike Zone Alpha
BASE,DR-003,ScoutMini,100.0,0,0,None

---


------------------------------------------------------------
### ▶️ How to Run
------------------------------------------------------------
After compiling the program successfully, run the executable as follows:

*   On **Linux/macOS**:
   `. /drone-fleet   `

*   On **Windows**:
   `drone-fleet.exe `



------------------------------------------------------------
### 🔮 Future Improvements
------------------------------------------------------------
Here are some ideas you can implement to make the project even better:

🔋 Add battery recharge feature

📜 Maintain a mission history log

🔎 Filter drones by type (Surveillance / Attack)

🕒 Add real-time mission timers or durations

💻 GUI version using Qt or SFML for visual simulation

🌐 Convert to client-server model for drone network simulation

------------------------------------------------------------
### ✅ Summary
------------------------------------------------------------

This project is structured using best practices for C++:
- Multi-file modular design
- Object-oriented programming with clear inheritance
- Easy to compile, understand, and extend

It is ready for demonstration and submission for NASTP or similar technical evaluations.
