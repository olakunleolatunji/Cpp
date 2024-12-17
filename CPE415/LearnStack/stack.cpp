#include <iostream>
#include "stack.h"

Stack::Stack(int size) {
    this->size = size;
    values = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete[] values;
}

bool Stack::isFull() {
    if (top < size - 1) { 
        return false;
    } else {
        return true;
    }
}

bool Stack::isEmpty() {
    if (top == -1) { 
        return true;
    } else {
        return false;
    }
}

void Stack::push(int x) {
    if (!isFull()) {
        top++;
        values[top] = x;
    }
}

int Stack::pop() {
    if (!isEmpty()) {
        int retVal{0};
        if (!isEmpty()) { 
            retVal = values[top];
            top--;
        }
        return retVal;
    }
    return -1; 
}

int main() {
    Stack* stack = new Stack();

    stack->push(1);
    stack->push(2);
    stack->push(3);

    for (int i = 0; i < 3; i++) {
        std::cout << stack->pop() << std::endl;
    }

    // Clean up memory
    delete stack;

    return 0;
}
