//Berkay Simsek, section 2, 22303338
#ifndef CITY_H
#define CITY_H

class City {
public:
    City();
    int getState() const;
    void setState(int state);
    void setIndexForRow(int row);
    int getIndexForRow() const;
    void setIndexForColumn(int column);
    int getIndexForColumn() const;

private:
    int currentState;
    int indexForRow;
    int indexForColumn;
};

#endif //CITY_H
