#include <iostream>
#include "queuelinkedlist.cpp"


int main(){
    QueueLinkedList* queue = new QueueLinkedList();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    std::cout << queue->dequeue() << std::endl;
    delete queue;

    return 0;
}