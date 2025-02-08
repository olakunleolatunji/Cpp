#include "queuelinkedlist.h"
#include <iostream>

// linkedlist.cpp
LinkedList::LinkedList(){
    front = nullptr;
    back = nullptr;
}

LinkedList::~LinkedList(){
    destroyList();
}

void LinkedList::appendNode(int data){
    NODE* n = new NODE(data);
    if(front == nullptr){
        back = n;
        front = n;
    }
    else{
        back->next = n;
        n->previous = back;
        back = n;
    }
}

void LinkedList::displayNodes(){
    std::cout << "Nodes: ";
    NODE* temp = front;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

}

void LinkedList::displayNodesReverse(){
    std::cout << "Nodes in reverse: ";
    NODE* temp = back;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->previous;
    }
}

void LinkedList::destroyList(){
    NODE* temp = back;
    while (temp != nullptr){
        NODE* temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
    back = nullptr;
    front = nullptr;
}

// queuelinkedlist.cpp
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
    if(front->next == nullptr){
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

// demo.cpp
int main(){
    QueueLinkedList* queue = new QueueLinkedList();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    std::cout << queue->dequeue() << std::endl;
    delete queue;

    return 0;
}