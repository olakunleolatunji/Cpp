#include <iostream>
#include "enhancedLinkedList.h"
using namespace std;

// Linked List Functions
LinkedList::LinkedList()
{
    front = nullptr;
    back = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    destroyList();
}

void LinkedList::appendNode(int data)
{
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
    size++;
}

void LinkedList::displayNodes()
{
    cout << "Nodes: ";
    NODE* temp = front;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::displayNodesReverse()
{
    cout << "Nodes Reversed: ";
    NODE* temp = back;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->previous;
    }
}

void LinkedList::destroyList()
{
    NODE* temp = back;
    while(temp != nullptr){
        NODE* temp2 = temp;
        temp =  temp->previous;
        delete temp2;
    }
    back = nullptr;
    front = nullptr;
    size = 0;
}

void LinkedList::removeNode(NODE* node){
    if(node->previous == nullptr && node->next==nullptr){
        back = nullptr;
        front = nullptr;
    }
    else if(node-> previous == nullptr){
        front = node->next;
        node->next->previous = nullptr;
    }
    else if(node->next==nullptr){
        back = node->previous;
        node->previous->next = nullptr;
    }
    else{
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    delete node;
    size--;
}

void LinkedList::removeNodeAt(int index){
    if(index < 0 || index > (size-1)){
        cout << "Index out of bounds" << endl;
        return;
    }
    NODE* temp = front;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    removeNode(temp);
}

int LinkedList::findNode(int data){
    NODE* temp = front;
    int index = 0;
    while(temp != nullptr){
        if(temp->data == data){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void LinkedList::deleteNode(int data){
    NODE* temp = front;
    while(temp != nullptr){
        if(temp->data == data){
            removeNode(temp);
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::insertNodeAt(int index, int data){
    if(index < 0 || index > size){
        cout << "Index out of bounds" << endl;
        return;
    }
    NODE* n = new NODE(data);
    if(size == 0){
        front = n;
        back = n;
    }
    else if(index == 0){
        n->next = front;
        front->previous = n;
        front = n;
    }
    else if(index == size){
        back->next = n;
        n->previous = back;
        back = n;
    }
    else{
        NODE* temp = front;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        n->next = temp;
        n->previous = temp->previous;
        temp->previous->next = n;
        temp->previous = n;
    }
    size++;
}

int LinkedList::peek(int index){
    if(index < 0 || index > (size-1)){
        cout << "Index out of bounds" << endl;
        return -1;
    }
    NODE* temp = front;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

int LinkedList::getSize(){
    return size;
}

int main()
{
LinkedList* list = new LinkedList();
list->appendNode(10);
list->appendNode(20);
list->appendNode(30);
list->appendNode(40);
list->appendNode(50);
list->removeNodeAt(3);
int index = list->findNode(20);
list->deleteNode(20);
list->insertNodeAt(1, 35);
int data = list->peek(3);
int size = list->getSize();

delete list;
}