typedef struct Node{
    int data;
    struct Node* previous;
    struct Node* next;

    Node(int data){
        this->data = data;
        previous = nullptr;
        next = nullptr;
    }
} NODE;

class LinkedList{
    private:
        NODE* front = nullptr;
        NODE* back = nullptr;
    public:
        LinkedList();
        ~LinkedList();
        void appendNode(int);
        void displayList();
        void displayListReversed();
        void destroyList();
};