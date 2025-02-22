//Section 2, Berkay Simsek, 22303338
#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <string>
#include "Mission.h"
using namespace std;

class Mission;
class Spacecraft {

public:
    Spacecraft(const string name, const string type);
    Spacecraft();
    ~Spacecraft();
    void setName(const string spacecraftName);
    void setType(const string spacecraftType);
    void setAssignedMission(Mission* mission);
    void setStatus(const bool status);
    void removeAssignedMission();
    void displaySpacecraft() const;
    bool getStatus() const;
    Mission* getAssignedMission() const;
    string getName() const;
    string getType() const;

private:
    string name;
    string type;
    bool isAssigned;
    Mission *assignedMission;
};

#endif // SPACECRAFT_H
