typedef struct Node{
    int data;
    struct Node* previous;
    struct Node* next;

    Node (int data){
        this->data = data;
        previous = nullptr;
        next = nullptr;
    }
} NODE;

class LinkedList{
    protected:
        NODE* front = nullptr;
        NODE* back = nullptr;
        int size;
        void removeNode(NODE* node);
    public:
        LinkedList();
        virtual ~LinkedList();
        void appendNode(int);
        void displayNodes();
        void displayNodesReverse();
        void destroyList();
        void removeNode(int);
        void removeNodeAt(int);
        int findNode(int);
        void deleteNode(int);
        void insertNodeAt(int,int);
        int peek(int);
        int getSize();
};  