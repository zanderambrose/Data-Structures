#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
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
        Node *newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        this->length = 1;
    }
    void printList()
    {
        Node *temp = this->head;
        while (temp)
        {
            std::cout << temp->value << ", " << std::endl;
            temp = temp->next;
        }
    }
    void getHead()
    {
        std::cout << this->head->value << std::endl;
    }
    void getTail()
    {
        std::cout << this->tail->value << std::endl;
    }
    void getLength()
    {
        std::cout << this->length << std::endl;
    }
};

int main()
{
    LinkedList *myLinkedList = new LinkedList(1);
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    return 0;
}