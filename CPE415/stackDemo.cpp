#include <iostream>
#include "stack.h"

int main(){
    Stack* stack = new Stack();

    stack->push(1);
    stack->push(2); 
    stack->push(3); 

    for(int i = 0; i < 3; i++){
        std::cout << stack->pop() << std::endl;
    }

    delete stack;

    return 0;
}