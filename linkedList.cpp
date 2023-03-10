class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = nullptr;
    };
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *node = new Node(value);
        this->head = node;
        this->tail = node;
        this->length = 1;
    };
};
