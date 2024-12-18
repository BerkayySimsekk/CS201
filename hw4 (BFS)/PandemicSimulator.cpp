#include "PandemicSimulator.h"
#include "ListQueue.cpp"

#include <fstream>
#include <iostream>

PandemicSimulator::PandemicSimulator(const string cityGridFile) {
    dayCounter = 0;
    cityGridFileName = cityGridFile;
    gridInfo = nullptr;
    readGridInfoFromFile(cityGridFile);
}

PandemicSimulator::~PandemicSimulator() {
    for(int i = 0; i < firstDim; i++) {
        for(int j = 0; j < secondDim; j++)
            delete gridInfo[i][j];

        delete gridInfo[i];
    }

    delete gridInfo;
}

void PandemicSimulator::readGridInfoFromFile(const string cityGridFile) {
    if(gridInfo != nullptr) {
        for(int i = 0; i < firstDim; i++) {
            for(int j = 0; j < secondDim; j++)
                delete gridInfo[i][j];

            delete gridInfo[i];
        }

        delete gridInfo;
    }

    ifstream inputFile(cityGridFile);
    char ch;
    int number;
    int dimCount = 1;

    while(inputFile.get(ch) && dimCount <= 2) {
        if(ch == '\n' || isspace(ch))
            continue;

        number = ch - '0';

        if(dimCount == 1)
            firstDim = number;
        else
            secondDim = number;

        dimCount++;
    }

    gridInfo = new City**[firstDim];

    for(int i = 0; i < firstDim; i++)
        gridInfo[i] = new City*[secondDim];

    for(int i = 0; i < firstDim; i++)
        for(int j = 0; inputFile.get(ch) && j < secondDim; j++) {
            number = ch - '0';

            City* city = new City();
            city->setState(number);
            city->setIndexForRow(i);
            city->setIndexForColumn(j);

            gridInfo[i][j] = city;
        }
}

void PandemicSimulator::simulateBlock(const int row, const int col) {
    ListQueue<City*> cityQueue;

    for(int i = 0; i < firstDim; i++)
        for(int j = 0; j < secondDim; j++)
            if(gridInfo[i][j]->getState() == 2)
                cityQueue.enqueue(gridInfo[i][j]);

    City* nextDay = new City();
    nextDay->setState(3);
    cityQueue.enqueue(nextDay);

    int checkingIndexForRow;
    int checkingIndexForCol;
    bool isFound = false;

    while(!cityQueue.isEmpty() && !isFound) {
        if(cityQueue.peekFront()->getState() == 3) {
            cityQueue.dequeue();
            if(!cityQueue.isEmpty()) {
                dayCounter++;
                cityQueue.enqueue(nextDay);
            }
        }
        else {
            checkingIndexForRow = cityQueue.peekFront()->getIndexForRow();
            checkingIndexForCol = cityQueue.peekFront()->getIndexForColumn();

            if(checkingIndexForRow == row && checkingIndexForCol == col)
                isFound = true;
            else {
                cityQueue.dequeue();

                if(checkingIndexForRow + 1 < firstDim) {
                    if(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->getState() == 1) {
                        cityQueue.enqueue(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]);
                        gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->setState(2);
                    }
                }

                if(checkingIndexForRow - 1 >= 0) {
                    if(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->getState() == 1) {
                        cityQueue.enqueue(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]);
                        gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->setState(2);
                    }
                }

                if(checkingIndexForCol + 1 < secondDim) {
                    if(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->getState() == 1) {
                        cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]);
                        gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->setState(2);
                    }
                }

                if(checkingIndexForCol - 1 >= 0) {
                    if(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->getState() == 1) {
                        cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]);
                        gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->setState(2);
                    }
                }
            }
        }
    }

    delete nextDay;

    if(!isFound)
        dayCounter = -1;

    cout << "Time for block (" << row << ", " << col << ") to be infected: " << dayCounter << " days." << endl;

    dayCounter = 0;
    readGridInfoFromFile(cityGridFileName);
}

void PandemicSimulator::simulatePandemic() {
    ListQueue<City*> cityQueue;

    for(int i = 0; i < firstDim; i++)
        for(int j = 0; j < secondDim; j++)
            if(gridInfo[i][j]->getState() == 2)
                cityQueue.enqueue(gridInfo[i][j]);

    City* nextDay = new City();
    nextDay->setState(3);
    cityQueue.enqueue(nextDay);

    int checkingIndexForRow;
    int checkingIndexForCol;

    while(!cityQueue.isEmpty()) {
        if(cityQueue.peekFront()->getState() == 3) {
            cityQueue.dequeue();
            if(!cityQueue.isEmpty()) {
                dayCounter++;
                cityQueue.enqueue(nextDay);
            }
        }
        else {
            checkingIndexForRow = cityQueue.peekFront()->getIndexForRow();
            checkingIndexForCol = cityQueue.peekFront()->getIndexForColumn();

            cityQueue.dequeue();

            if(checkingIndexForRow + 1 < firstDim) {
                if(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]);
                    gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->setState(2);
                }
            }

            if(checkingIndexForRow - 1 >= 0) {
                if(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]);
                    gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->setState(2);
                }
            }

            if(checkingIndexForCol + 1 < secondDim) {
                if(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]);
                    gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->setState(2);
                }
            }

            if(checkingIndexForCol - 1 >= 0) {
                if(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]);
                    gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->setState(2);
                }
            }
        }
    }

    delete nextDay;

    bool isSpreadAllBlocks = true;

    for(int i = 0; i < firstDim && isSpreadAllBlocks; i++)
        for(int j = 0; j < secondDim && isSpreadAllBlocks; j++)
            if(gridInfo[i][j]->getState() == 1)
                isSpreadAllBlocks = false;

    if(isSpreadAllBlocks)
        cout << "Minimum time for pandemic to spread to all blocks: " << dayCounter << " days." << endl;
    else
        cout << "Pandemic cannot spread to all blocks." << endl;

    readGridInfoFromFile(cityGridFileName);
}

void PandemicSimulator::displayCityState(const int time) {
    ListQueue<City*> cityQueue;

    for(int i = 0; i < firstDim; i++)
        for(int j = 0; j < secondDim; j++)
            if(gridInfo[i][j]->getState() == 2)
                cityQueue.enqueue(gridInfo[i][j]);

    City* nextDay = new City();
    nextDay->setState(3);
    cityQueue.enqueue(nextDay);

    int checkingIndexForRow;
    int checkingIndexForCol;

    while(!cityQueue.isEmpty() && dayCounter < time) {
        if(cityQueue.peekFront()->getState() == 3) {
            cityQueue.dequeue();
            if(!cityQueue.isEmpty()) {
                dayCounter++;
                cityQueue.enqueue(nextDay);
            }
        }
        else {
            checkingIndexForRow = cityQueue.peekFront()->getIndexForRow();
            checkingIndexForCol = cityQueue.peekFront()->getIndexForColumn();

            cityQueue.dequeue();

            if(checkingIndexForRow + 1 < firstDim) {
                if(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow + 1][checkingIndexForCol]);
                    gridInfo[checkingIndexForRow + 1][checkingIndexForCol]->setState(2);
                }
            }

            if(checkingIndexForRow - 1 >= 0) {
                if(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow - 1][checkingIndexForCol]);
                    gridInfo[checkingIndexForRow - 1][checkingIndexForCol]->setState(2);
                }
            }

            if(checkingIndexForCol + 1 < secondDim) {
                if(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol + 1]);
                    gridInfo[checkingIndexForRow][checkingIndexForCol + 1]->setState(2);
                }
            }

            if(checkingIndexForCol - 1 >= 0) {
                if(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->getState() == 1) {
                    cityQueue.enqueue(gridInfo[checkingIndexForRow][checkingIndexForCol - 1]);
                    gridInfo[checkingIndexForRow][checkingIndexForCol - 1]->setState(2);
                }
            }
        }
    }

    delete nextDay;

    cout << "City state at day " << time << ":" << endl;

    for(int i = 0; i < firstDim; i++) {
        for(int j = 0; j < secondDim; j++)
            cout << gridInfo[i][j]->getState();
        cout << endl;
    }

    dayCounter = 0;
    readGridInfoFromFile(cityGridFileName);
}



