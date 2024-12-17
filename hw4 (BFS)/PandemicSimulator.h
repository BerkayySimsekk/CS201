#ifndef PANDEMICSIMULATOR_H
#define PANDEMICSIMULATOR_H

#include "City.h"

#include <string>
using namespace std;

class PandemicSimulator {
public:
    PandemicSimulator(const string cityGridFile);
    ~PandemicSimulator();

    void displayCityState(const int time);
    void simulateBlock(const int row, const int col);
    void simulatePandemic();
    void readGridInfoFromFile(const string cityGridFile);

private:
    string cityGridFileName;
    int dayCounter;
    int firstDim;
    int secondDim;
    City*** gridInfo;
};

#endif //PANDEMICSIMULATOR_H
