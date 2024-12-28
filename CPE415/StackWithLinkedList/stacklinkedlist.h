// NORMAL LINKED LIST PART

typedef struct Node{
    int data;
    struct Node* previous;
    struct Node* next;
    
    // The books uses "struct Node", but this causes an error, so just "Node" works fine
    Node(int data){
        this->data = data;
        previous = nullptr;
        next = nullptr;
    }
} NODE;

class LinkedList{
    protected:
        NODE* front;
        NODE* back;
    public:
        LinkedList();
        ~LinkedList();
        void appendNode(int);
        void displayNodes();
        void displayNodesReverse();
        void destroyList();
};

// STACK LINKED LIST PART

class StackLinkedList : public LinkedList{
    public:
        StackLinkedList();
        virtual ~StackLinkedList();
        void push(int);
        int pop();
        bool isEmpty();
};