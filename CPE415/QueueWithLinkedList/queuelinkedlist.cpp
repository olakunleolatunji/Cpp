#include "queuelinkedlist.h"

QueueLinkedList::QueueLinkedList(){}

QueueLinkedList::~QueueLinkedList(){}

void QueueLinkedList::enqueue(int data){
    appendNode(data);
}

int QueueLinkedList::dequeue(){
    if(isEmpty()){
        return -1;
    }
    int retVal = front->data;
    NODE* temp = front;
    if(front->next = nullptr){
        front = nullptr;
        back = nullptr;
    }
    else{
        front = front->next;
        front->previous = nullptr;
    }
    delete temp;
    return retVal;
}

bool QueueLinkedList::isEmpty(){
    if (front == nullptr){
        return true;
    }
    else{
        return false;
    }
    }