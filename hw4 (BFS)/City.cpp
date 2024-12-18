//Berkay Simsek, section 2, 22303338
#include "City.h"

City::City() {
    currentState = 0;
    indexForRow = 0;
    indexForColumn = 0;
}

void City::setState(int state) {
    currentState = state;
}

int City::getState() const {
    return currentState;
}

void City::setIndexForRow(int row) {
    indexForRow = row;
}

int City::getIndexForRow() const {
    return indexForRow;
}

void City::setIndexForColumn(int column) {
    indexForColumn = column;
}

int City::getIndexForColumn() const {
    return indexForColumn;
}




