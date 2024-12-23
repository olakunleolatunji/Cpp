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
    if(back==nullptr){
        back = n;
        front = n;
    }
    else{
        back->next = n;
        n->previous = back;
        back = n;
    }
}

void LinkedList::displayList(){
    std::cout << "Nodes: ";
    NODE* temp = front;

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::displayListReversed(){
    std::cout << "Nodes Reversed: ";
    NODE* temp = back;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->previous;
    }
}

void LinkedList::destroyList(){
    NODE* temp = back;
    while(temp != nullptr){
        NODE* temp2 = temp;
        temp =  temp->previous;
        delete temp2;
    }
    back = nullptr;
    front = nullptr;
}

int main(){
    LinkedList* list = new LinkedList();
    list->appendNode(10);
    list->appendNode(20);
    list->appendNode(30);

    list->displayList();
    list->displayListReversed();
    
    delete list;

    return 0;
}