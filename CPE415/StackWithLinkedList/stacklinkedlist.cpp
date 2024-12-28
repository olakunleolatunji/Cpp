#include "stacklinkedlist.h"
#include <iostream>

// NORMAL LINKED LIST PART

LinkedList::LinkedList(){
    front = NULL;
    back = NULL;
}

LinkedList::~LinkedList(){
    destroyList();
}

void LinkedList::appendNode(int data){
    NODE* n = new NODE(data);
    if(back == nullptr){
        back = n;
        front = n;
    }
    else{
        back->next = n;
        n->previous =  back;
        back = n;
    }
}

void LinkedList::displayNodes(){
    std::cout << "Nodes: ";
    NODE* temp = front;
    while(temp != nullptr){
        std::cout << " " << temp->data;
        temp = temp->next;
    }
}

void LinkedList::displayNodesReverse(){
    std::cout << "Nodes Reversed: ";
    NODE* temp = back;
    while(temp != nullptr){
        std::cout << " " << temp->data;
        temp = temp->previous;
    }
}

void LinkedList::destroyList(){
    NODE* temp = back;
    while(temp != nullptr){
        NODE* temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
    back = nullptr;
    front = nullptr;
}

// STACK LINKED LIST PART

StackLinkedList::StackLinkedList(){
}

StackLinkedList::~StackLinkedList(){
}

void StackLinkedList::push(int x){
    appendNode(x);
}

int StackLinkedList::pop(){
    if(isEmpty()){
        return -1;
    }
    int retVal = back->data;
    NODE* temp = back;
    if(back->previous == nullptr){
        back = nullptr;
        front = nullptr;
    }
    else{
        back = back->previous;
        back->next = nullptr;
    }
    delete temp;
    return retVal;
}

bool StackLinkedList::isEmpty(){
    if(front == nullptr){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    StackLinkedList* stack = new StackLinkedList();
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->displayNodes();
    std::cout << stack->pop() << std::endl;
    delete stack;
}