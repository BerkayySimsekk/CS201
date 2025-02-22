//Berkay Simsek 22303338
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.cpp"
#include "ListInterface.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    void insert(int newPosition, const ItemType& newEntry);
    void remove(int position);
    void clear();
    ItemType& getEntry(int position) const;
};

template<class ItemType>
LinkedList<ItemType>::LinkedList() {
    headPtr = nullptr;
    itemCount = 0;
}

template< class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template< class ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}

template< class ItemType>
ItemType& LinkedList<ItemType>::getEntry(int position) const {
    Node<ItemType>* nodePtr = getNodeAt(position);
    return nodePtr->getItem();
}

template< class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    Node<ItemType>* curPtr = headPtr;
    for( int i = 1; i < position; i++)
        curPtr = curPtr->getNext();
    return curPtr ;
}

template< class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    if(newPosition >= 1 && newPosition <= itemCount + 1) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        if (newPosition == 1) {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else {
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
}

template<class ItemType>
void LinkedList<ItemType>::remove(int position) {
    if(position >= 1 && position <= itemCount)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1) {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else {
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }
}

template< class ItemType>
void LinkedList<ItemType>::clear() {
    while (!isEmpty())
        remove(1);
}

template< class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

#endif // LINKEDLIST_H

