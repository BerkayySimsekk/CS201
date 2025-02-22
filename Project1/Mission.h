//Section 2, Berkay Simsek, 22303338
#ifndef MISSION_H
#define MISSION_H

#include <string>
#include "Spacecraft.h"
using namespace std;

class Spacecraft;
class Mission {

public:
    Mission(const string name, const string launchDate, const string destination);
    Mission();
    ~Mission();
    void setName(const string missionName);
    void setLaunchDate(const string missionLaunchDate);
    void setDestination(const string missionDestination);
    string getName() const;
    string getLaunchDate() const;
    string getDestination() const;
    Spacecraft** getAssignedSpacecrafts() const;
    void displayStyleAllMissions() const;
    void displayStyleSingleMission() const;
    void addAssignedSpacecraftToMission(Spacecraft* spacecraft);
    void removeAssignedSpacecraftFromMission(Spacecraft* spacecraft);

private:
    string name;
    string launchDate;
    string destination;
    int assignedSpacecraftsCount;
    Spacecraft** assignedSpacecrafts;
};

#endif // MISSION_H
