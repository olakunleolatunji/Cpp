#include <iostream>
#include "stack.h"

using std::cout, std::cin, std::endl;

int precedence(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

Stack::Stack(int size){
    this->size = size;
    top = -1;
    stack = new char[size]; // Allocate memory for the stack
}

Stack::~Stack(){
    delete[] stack;
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isFull(){
    if(top == (size-1)){
        return true;
    }
    else return false;
}

void Stack::push(char c){
    if(!isFull()){
        top++;
        stack[top] = c;
    }
}

char Stack::pop(){
    char c;
    if(!isEmpty()){
        c = stack[top];
        top--;
        return c;
    }
    else{
        throw std::runtime_error("Cannot pop from an empty stack");
    }
}

char Stack::peek(){
    if (top < 0){
        throw std::runtime_error("Cannot peek into an empty stack");
    }
    else{
        return stack[top];
    }
}

string infixToPostfix(string infix, string postfix, Stack* stack){
    for(char& c : infix){
        if (isalpha(c)){
            postfix += c;
        }
        else if(c == '('){
            stack->push(c);
        }
        else if(c=='+' || c=='-' || c=='/' || c=='*'){
            bool popOperators = true;
            do{
                if(stack->isEmpty()){
                    stack->push(c);
                    popOperators = false;
                }
                else if(stack->peek() == '('){
                    stack->push(c);
                    popOperators = false;
                }
                else if(precedence(c) > precedence(stack->peek())){
                    stack->push(c);
                    popOperators = false;
                }
                else{
                    postfix += stack->pop();
                }
            } while (popOperators);
        }
        else if(c == ')'){
            bool popOperators = true;
            do{
                postfix += stack->pop();
                if(stack->peek() == '('){
                    popOperators = false;
                    char discard = stack->pop();
                }
            } while (popOperators);
        }

    }

    while(!stack->isEmpty()){
        postfix += stack->pop();
    }
    
    return postfix;
}

int main(){
    Stack* stack = new Stack(30);
    string infix;
    string postfix = "";

    cin >> infix;

    cout << endl << infixToPostfix(infix, postfix, stack) << endl;

    delete stack; // Deallocate the stack - important to prevent memory leaks
    return 0;
}