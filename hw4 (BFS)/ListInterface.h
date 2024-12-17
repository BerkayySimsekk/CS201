//Berkay Simsek 22303338
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template<class ItemType>
class ListInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual void insert(int newPosition, const ItemType& newEntry) = 0;
    virtual void remove(int position) = 0;
    virtual void clear() = 0;
    virtual ItemType& getEntry(int position) const = 0;
    virtual int getLength() const = 0;
    virtual ~ListInterface() {}
};

#endif //LISTINTERFACE_H
