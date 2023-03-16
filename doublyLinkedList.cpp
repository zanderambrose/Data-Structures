#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node *previous;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class DoublyLinkedList
{
private:
    int length;
    Node *head;
    Node *tail;

public:
    DoublyLinkedList(int value)
    {
        Node *firstNode = new Node(value);
        this->head = firstNode;
        this->tail = firstNode;
        this->length = 1;
    }
    void getHead()
    {
        std::cout << "Head: " << this->head->value << std::endl;
    }
    void getTail()
    {
        std::cout << "Tail: " << this->tail->value << std::endl;
    }
    void printList()
    {
        Node *current = this->head;
        while (current)
        {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }
};