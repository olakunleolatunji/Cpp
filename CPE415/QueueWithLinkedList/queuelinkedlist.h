// linkedlist.h
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* previous;

    Node(int data){
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }
}NODE;

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

// queuelinkedlist.h
class QueueLinkedList : public LinkedList{
    public:
        QueueLinkedList();
        ~QueueLinkedList();
        void enqueue(int data);
        int dequeue();
        bool isEmpty();
};