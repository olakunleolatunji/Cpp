#define MAX_SIZE 50
#include <string>
using std::string;

class Stack{
    private:
        int size;
        int top;
        char* stack;
    public:
        Stack(int size=MAX_SIZE);
        virtual ~Stack();
        void push(char c);
        char pop();
        char peek();
        bool isEmpty();
        bool isFull();
};

int precedence(char);
string infixToPostfix(string, string , Stack*);