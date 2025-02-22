//Berkay Simsek 22303338
#ifndef NODE_H
#define NODE_H

#include <cstddef>
using namespace std;

template<class ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType& getItem();
    Node<ItemType>* getNext();
};

template<class ItemType>
Node<ItemType>::Node() {
    next = nullptr;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) {
    next = nullptr;
    item = anItem;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {
    item = anItem;
    next = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

template<class ItemType>
ItemType& Node<ItemType>::getItem() {
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() {
    return next;
}

#endif // NODE_H






