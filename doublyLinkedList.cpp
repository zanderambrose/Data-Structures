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
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (this->length == 1)
        {
            this->head->next = newNode;
            newNode->previous = this->head;
            this->tail = newNode;
        }
        else
        {

            this->tail->next = newNode;
            newNode->previous = this->tail;
            this->tail = newNode;
        }
        this->length++;
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
            std::cout << current->value << ", ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyLinkedList *myDll = new DoublyLinkedList(10);

    myDll->printList();

    myDll->append(4);
    myDll->append(9);
    myDll->append(6);
    myDll->append(2);
    myDll->append(4);
    myDll->printList();
    myDll->getHead();
    myDll->getTail();
}