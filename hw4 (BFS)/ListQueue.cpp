#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "QueueInterface.h"
#include "LinkedList.cpp"

template<class ItemType>
class ListQueue : public QueueInterface<ItemType> {
private:
    LinkedList<ItemType>* listPtr; // Pointer to list of queue items
public:
    ListQueue();
    ~ListQueue();
    bool isEmpty() const;
    void enqueue(const ItemType& newEntry);
    void dequeue();
    ItemType peekFront() const;
};

template<class ItemType>
ListQueue<ItemType>::ListQueue() {
    listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
ListQueue<ItemType>::~ListQueue() {
}

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

template<class ItemType>
void ListQueue<ItemType>::enqueue(const ItemType& newEntry) {
    listPtr->insert(listPtr->getLength() + 1, newEntry);
}

template<class ItemType>
void ListQueue<ItemType>::dequeue() {
    listPtr->remove(1);
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const {
    if (!isEmpty())
        return listPtr->getEntry(1);
    return nullptr;
}

#endif //LISTQUEUE_H
