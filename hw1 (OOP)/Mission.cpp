//Section 2, Berkay Simsek, 22303338
#include <iostream>
using namespace std;
#include "Mission.h"

//constructor
Mission::Mission(const string name, const string launchDate, const string destination) {
    setName(name);
    setLaunchDate(launchDate);
    setDestination(destination);
    assignedSpacecraftsCount = 0;
    assignedSpacecrafts = nullptr;
}

//default constructor
Mission::Mission() {
    setName("");
    setLaunchDate("");
    setDestination("");
    assignedSpacecraftsCount = 0;
    assignedSpacecrafts = nullptr;
}

//destructor
Mission:: ~Mission() {
    for(int i = 0; i < assignedSpacecraftsCount; i++) {
        assignedSpacecrafts[i]->setStatus(false);
    }

    delete[] assignedSpacecrafts;
}

//setters
void Mission::setName(const string missionName) {
    name = missionName;
}

void Mission::setLaunchDate(const string missionLaunchDate) {
    launchDate = missionLaunchDate;
}

void Mission::setDestination(const string missionDestination) {
    destination = missionDestination;
}

//getters
string Mission::getName() const {
    return name;
}

string Mission::getLaunchDate() const {
    return launchDate;
}

string Mission::getDestination() const {
    return destination;
}

Spacecraft** Mission::getAssignedSpacecrafts() const {
    return assignedSpacecrafts;
}

//assigning the given spacecraft to the mission
void Mission::addAssignedSpacecraftToMission(Spacecraft* spacecraft) {
    assignedSpacecraftsCount++;

    //if there are no assigned spacecrafts to the mission, a dynamically allocated array is created with size of 1
    if(assignedSpacecrafts == nullptr) {
        assignedSpacecrafts = new Spacecraft*[assignedSpacecraftsCount];
        assignedSpacecrafts[0] = spacecraft;
    }
    //if there are already assigned spacecrafts to the mission, a temporary dynamically allocated array is created with a size greater by one from the previous size,
    //the newly created array is filled with the given spacecraft and already existing spacecrafts
    else {
        Spacecraft** temp = new Spacecraft*[assignedSpacecraftsCount];

        for(int i = 0; i < assignedSpacecraftsCount - 1; i++) {
            temp[i] = assignedSpacecrafts[i];
        }

        delete[] assignedSpacecrafts;
        temp[assignedSpacecraftsCount - 1] = spacecraft;
        assignedSpacecrafts = temp;
    }
}

//removing the given spacecraft from the mission
void Mission::removeAssignedSpacecraftFromMission(Spacecraft* spacecraft) {
    int indexOfFoundSpacecraft = -1;

    //finding the index of the spacecraft that is supposed to be removed
    for(int i = 0; i < assignedSpacecraftsCount; i++) {
        if(assignedSpacecrafts[i]->getName() == spacecraft->getName()) {
            indexOfFoundSpacecraft = i;
        }
    };

    assignedSpacecraftsCount--;

    //the temporary dynamically allocated array is created with a size smaller by one from the previous size, the newly created array is filled with the spacecrafts except
    //for the one that should be removed
    Spacecraft** temp = new Spacecraft*[assignedSpacecraftsCount];

    for(int i = 0; i < indexOfFoundSpacecraft; i++) {
        temp[i] = assignedSpacecrafts[i];
    }

    for(int i = indexOfFoundSpacecraft, j = indexOfFoundSpacecraft + 1; i < assignedSpacecraftsCount; i++, j++) {
        temp[i] = assignedSpacecrafts[j];
    }

    delete[] assignedSpacecrafts;
    assignedSpacecrafts = temp;
}

//displaying the name, launch date, destination and the count for the assigned spacecrafts
void Mission::displayStyleAllMissions() const {
    cout << "Mission: " << name << ", Launch Date: " << launchDate << ", Destination: " << destination << ", Assigned Spacecraft Count: " << assignedSpacecraftsCount << endl;
}

//displaying the name, launch date, destination and the name of the assigned spacecrafts to this mission
void Mission::displayStyleSingleMission() const {
    cout << "Mission:" << endl;
    cout << "  Name: " << name << endl;
    cout << "  Launch Date: " << launchDate << endl;
    cout << "  Destination: " << destination << endl;
    cout << "  Assigned Spacecrafts:" << endl;
    for(int i = 0; i < assignedSpacecraftsCount; i++) {
        cout << "  - " << assignedSpacecrafts[i]->getName() << endl;
    }
    if(assignedSpacecraftsCount == 0) {
        cout << "    None" << endl;
    }
}













