//Section 2, Berkay Simsek, 22303338
#include <iostream>
using namespace std;
#include "SpaceMissionManagementSystem.h"

//default constructor
SpaceMissionManagementSystem::SpaceMissionManagementSystem() {
    missionListSize = 0;
    spacecraftListSize = 0;
    missionList = nullptr;
    spacecraftList = nullptr;
}

//destructor
SpaceMissionManagementSystem::~SpaceMissionManagementSystem() {
    if(missionList != nullptr) {
        for(int i = 0; i < missionListSize; i++) {
            if(missionList[i] != nullptr) {
                delete missionList[i];
            }
        }
        delete missionList;
    }

    if(spacecraftList != nullptr) {
        for(int i = 0; i < spacecraftListSize; i++) {
            if(spacecraftList[i] != nullptr) {
                delete spacecraftList[i];
            }
        }
        delete spacecraftList;
    }
}

//adding a mission to the list if the given mission does not have the same name with the already existing missions
void SpaceMissionManagementSystem:: addMission( const string name, const string launchDate, const string destination ) {
    bool isNotFound = true;

    for(int i = 0; i < missionListSize; i++) {
        if(missionList[i]->getName() == name) {
            isNotFound = false;
        }
    }

    if(isNotFound) {
        Mission* newMission = new Mission(name, launchDate, destination);
        missionListSize++;

        if(missionList == nullptr) {
            missionList = new Mission*[missionListSize];
            missionList[0] = newMission;
        }
        else {
            Mission** temp = new Mission*[missionListSize];

            for(int i = 0; i < missionListSize - 1; i++) {
                temp[i] = missionList[i];
            }

            delete[] missionList;
            temp[missionListSize - 1] = newMission;
            missionList = temp;
        }

        cout << "Added mission " << name << "." << endl;
    }
    else {
        cout << "Cannot add mission. Mission " << name << " already exists." << endl;
    }
}

//removing a mission from the list if a mission with the given name can be found
void SpaceMissionManagementSystem:: removeMission( const string name ) {
    bool isFound = false;
    int indexOfFoundMission = -1;

    for(int i = 0; i < missionListSize; i++) {
        if(missionList[i]->getName() == name) {
            isFound = true;
            indexOfFoundMission = i;
        }
    }

    if(isFound) {
        missionListSize--;

        Mission** temp = new Mission*[missionListSize];

        for(int i = 0; i < indexOfFoundMission; i++) {
            temp[i] = missionList[i];
        }

        for(int i = indexOfFoundMission, j = indexOfFoundMission + 1; i < missionListSize; i++, j++) {
            temp[i] = missionList[j];
        }

        delete missionList[indexOfFoundMission];
        delete[] missionList;
        missionList = temp;

        cout << "Removed mission " << name << "." << endl;
    }
    else {
        cout << "Cannot remove mission. Mission " << name << " does not exist." << endl;
    }
}

//adding a spacecraft to the list, if there is not an already existing spacecraft with the given name
void SpaceMissionManagementSystem:: addSpacecraft( const string name, const string type ) {
    bool isNotFound = true;

    for(int i = 0; i < spacecraftListSize; i++) {
        if(spacecraftList[i]->getName() == name) {
            isNotFound = false;
        }
    }

    if(isNotFound) {
        Spacecraft* newSpacecraft = new Spacecraft(name, type);
        spacecraftListSize++;

        if(spacecraftList == nullptr) {
            spacecraftList = new Spacecraft*[spacecraftListSize];
            spacecraftList[0] = newSpacecraft;
        }
        else {
            Spacecraft** temp = new Spacecraft*[spacecraftListSize];

            for(int i = 0; i < spacecraftListSize - 1; i++) {
                temp[i] = spacecraftList[i];
            }

            delete[] spacecraftList;
            temp[spacecraftListSize - 1] = newSpacecraft;
            spacecraftList = temp;
        }

        cout << "Added spacecraft " << name << "." << endl;
    }
    else {
        cout << "Cannot add spacecraft. Spacecraft " << name << " already exists." << endl;
    }
}

//removing a spacecraft if a spacecraft with the given name can be found and this spacecraft is not assigned to any mission
void SpaceMissionManagementSystem:: removeSpacecraft( const string name ) {
    bool isFound = false;
    int indexOfFoundSpacecraft = -1;

    for(int i = 0; i < spacecraftListSize; i++) {
        if(spacecraftList[i]->getName() == name) {
            isFound = true;
            indexOfFoundSpacecraft = i;
        }
    }

    if(isFound) {
        if(spacecraftList[indexOfFoundSpacecraft]->getStatus()) {
            cout << "Cannot remove spacecraft. Spacecraft " << name << " is assigned to a mission." << endl;
        }
        else {
            spacecraftListSize--;

            Spacecraft** temp = new Spacecraft*[spacecraftListSize];

            for(int i = 0; i < indexOfFoundSpacecraft; i++) {
                temp[i] = spacecraftList[i];
            }

            for(int i = indexOfFoundSpacecraft, j = indexOfFoundSpacecraft + 1; i < spacecraftListSize; i++, j++) {
                temp[i] = spacecraftList[j];
            }

            delete spacecraftList[indexOfFoundSpacecraft];
            delete[] spacecraftList;
            spacecraftList = temp;

            cout << "Removed spacecraft " << name << "." << endl;
        }
    }
    else {
        cout << "Cannot remove spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
}

//assigning a mission to a spacecraft if there is a spacecraft with the given name and there is a mission with the given name; also, the spacecraft should not be assigned
//to any missions
void SpaceMissionManagementSystem:: assignSpacecraftToMission( const string spacecraftName, const string missionName ) {
    bool spacecraftIsFound = false;
    bool missionIsFound = false;
    bool spacecraftIsAlreadyAssignedToMission = false;
    int indexOfFoundSpacecraft = -1;
    int indexOfFoundMission = -1;

    for(int i = 0; i < spacecraftListSize; i++) {
        if(spacecraftList[i]->getName() == spacecraftName) {
            spacecraftIsFound = true;
            indexOfFoundSpacecraft = i;

            if(spacecraftList[indexOfFoundSpacecraft]->getStatus()) {
                spacecraftIsAlreadyAssignedToMission = true;
            }
        }
    }

    for(int i = 0; i < missionListSize; i++) {
        if(missionList[i]->getName() == missionName) {
            missionIsFound = true;
            indexOfFoundMission = i;
        }
    }

    if(!spacecraftIsFound) {
        cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName << " does not exist." << endl;
    }
    else if(!missionIsFound) {
        cout << "Cannot assign spacecraft. Mission " << missionName << " does not exist." << endl;
    }
    if(missionIsFound && spacecraftIsFound && spacecraftIsAlreadyAssignedToMission) {
        cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName << " is already assigned to mission " << spacecraftList[indexOfFoundSpacecraft]->getAssignedMission()->getName() << "." << endl;
    }
    if(missionIsFound && spacecraftIsFound && !spacecraftIsAlreadyAssignedToMission) {
        missionList[indexOfFoundMission]->addAssignedSpacecraftToMission(spacecraftList[indexOfFoundSpacecraft]);
        spacecraftList[indexOfFoundSpacecraft]->setAssignedMission(missionList[indexOfFoundMission]);
        spacecraftList[indexOfFoundSpacecraft]->setStatus(true);

        cout << "Assigned spacecraft " << spacecraftList[indexOfFoundSpacecraft]->getName() << " to mission " << missionList[indexOfFoundMission]->getName() << "." << endl;
    }
}

//dropping a mission from the spacecraft if there is a spacecraft with the given name; also, the spacecraft should have an assigned mission
void SpaceMissionManagementSystem:: dropSpacecraftFromMission( const string spacecraftName ) {
    bool spacecraftIsFound = false;
    bool spacecraftIsAssignedToMission = false;
    int indexOfFoundSpacecraft = -1;

    for(int i = 0; i < spacecraftListSize; i++) {
        if(spacecraftList[i]->getName() == spacecraftName) {
            spacecraftIsFound = true;
            indexOfFoundSpacecraft = i;

            if(spacecraftList[indexOfFoundSpacecraft]->getStatus()) {
                spacecraftIsAssignedToMission = true;
            }
        }
    }

    if(!spacecraftIsFound) {
        cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName << " does not exist." << endl;
    }
    if(spacecraftIsFound && !spacecraftIsAssignedToMission) {
        cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName << " is not assigned to any mission." << endl;
    }
    if(spacecraftIsFound && spacecraftIsAssignedToMission) {
        cout << "Dropped spacecraft " << spacecraftName << " from mission " << spacecraftList[indexOfFoundSpacecraft]->getAssignedMission()->getName() << "." << endl;

        spacecraftList[indexOfFoundSpacecraft]->getAssignedMission()->removeAssignedSpacecraftFromMission(spacecraftList[indexOfFoundSpacecraft]);
        spacecraftList[indexOfFoundSpacecraft]->removeAssignedMission();
        spacecraftList[indexOfFoundSpacecraft]->setStatus(false);
    }
}

//displaying all the missions created
void SpaceMissionManagementSystem:: showAllMissions() const {
    cout << "Missions in the space mission management system:" << endl;

    if(missionListSize == 0) {
        cout << "None" << endl;
    }
    else {
        for(int i = 0; i < missionListSize; i++) {
            missionList[i]->displayStyleAllMissions();
        }
    }
}

//displaying all the spacecrafts created
void SpaceMissionManagementSystem:: showAllSpacecrafts() const {
    cout << "Spacecrafts in the space mission management system:" << endl;

    if(spacecraftListSize == 0) {
        cout << "None" << endl;
    }
    else {
        for(int i = 0; i < spacecraftListSize; i++) {
            spacecraftList[i]->displaySpacecraft();
        }
    }
}

//displaying only a specific mission with the given name if a mission with the given name can be found
void SpaceMissionManagementSystem:: showMission( const string name ) const {
    bool isFound = false;

    for(int i = 0; i < missionListSize && !isFound; i++) {
        if(missionList[i]->getName() == name) {
            isFound = true;
            missionList[i]->displayStyleSingleMission();
        }
    }

    if(!isFound) {
        cout << "Cannot show mission. Mission " << name << " does not exist." << endl;
    }
}

//displaying only a specific spacecraft with the given name if a spacecraft with the given name can be found
void SpaceMissionManagementSystem:: showSpacecraft( const string name ) const {
    bool isFound = false;

    for(int i = 0; i < spacecraftListSize && !isFound; i++) {
        if(spacecraftList[i]->getName() == name) {
            isFound = true;
            spacecraftList[i]->displaySpacecraft();
        }
    }

    if(!isFound) {
        cout << "Cannot show spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
}
