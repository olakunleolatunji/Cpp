#include "linkedlist.h"
#include <iostream>

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