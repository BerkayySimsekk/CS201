//Section 2, Berkay Simsek, 22303338
#include <iostream>
using namespace std;
#include "Spacecraft.h"

//constructor
Spacecraft::Spacecraft(const string name, const string type) {
    setName(name);
    setType(type);
    isAssigned = false;
    assignedMission = nullptr;
}

//default constructor
Spacecraft::Spacecraft() {
    setName("");
    setType("");
    isAssigned = false;
    assignedMission = nullptr;
}

//destructor
Spacecraft::~Spacecraft() = default;

//getters
bool Spacecraft::getStatus() const {
    return isAssigned;
}

Mission* Spacecraft::getAssignedMission() const {
    return assignedMission;
}

string Spacecraft::getName() const {
    return name;
}

string Spacecraft::getType() const {
    return type;
}

//setters
void Spacecraft::setAssignedMission(Mission* mission) {
    assignedMission = mission;
}

void Spacecraft::setName(const string spacecraftName) {
    name = spacecraftName;
}

void Spacecraft::setStatus(const bool status) {
    isAssigned = status;
}

void Spacecraft::setType(const string spacecraftType) {
    type = spacecraftType;
}

void Spacecraft::removeAssignedMission() {
    assignedMission = nullptr;
}

//displaying the name, type and status of spacecraft
void Spacecraft::displaySpacecraft() const {
    string availability;
    if(!isAssigned) {
        availability = "Available";
    }
    else {
        availability = "Assigned";
    }

    cout << "Spacecraft: " << name << ", Type: " << type << ", Status: " << availability << endl;
}



