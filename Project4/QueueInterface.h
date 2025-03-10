//Berkay Simsek, section 2, 22303338
#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template< class ItemType>
class QueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual void enqueue( const ItemType& newEntry) = 0;
    virtual void dequeue() = 0;
    virtual ItemType peekFront() const = 0;
    virtual ~QueueInterface() {}
};

#endif //QUEUEINTERFACE_H
