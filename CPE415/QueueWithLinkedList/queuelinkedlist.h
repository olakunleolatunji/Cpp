#include "linkedlist.h"

class QueueLinkedList : public LinkedList{
    public:
        QueueLinkedList();
        ~QueueLinkedList();
        void enqueue(int data);
        int dequeue();
        bool isEmpty();
};