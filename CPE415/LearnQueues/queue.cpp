#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size){
    this->size = size;
    values = new int[size];
    front = 0;
    back = 0;
}

Queue::~Queue(){
    delete[] values;
}

bool Queue::isFull(){
    if( (back+1) % size == front){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::isEmpty(){
    if(back==front){
        return true;
    }
    else{return false;}
}

void Queue::enqueue(int x){
    if(!isFull()){
        back = (back+1) % size;
        values[back] = x;
    }
}

int Queue::dequeue(){
    if(!isEmpty()){
        front = (front+1) % size;
        return values[front];
    }
    return 0;
}

int main(){
    Queue* queue = new Queue(8);
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    for(int i=0; i<3; i++){
        cout << queue->dequeue() << endl;
    }

    return 0;
}