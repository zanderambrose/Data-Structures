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
    ~LinkedList()
    {
        Node *temp = this->head;
        while (this->head)
        {
            this->head = this->head->next;
            delete temp;
            temp = this->head;
        }
    }
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (this->length > 0)
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        else
        {
            this->head = newNode;
            this->tail = newNode;
        }
        this->length++;
    }
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (this->length == 0)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {

            newNode->next = this->head;
            this->head = newNode;
        }
        this->length++;
    }
    void deleteLast()
    {
        if (this->length == 0)
            return;
        Node *temp = this->head;
        if (this->length == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *prev = this->head;
            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            this->tail = prev;
            this->tail->next = nullptr;
        }
        delete temp;
        this->length--;
    }
    void printList()
    {
        Node *temp = this->head;
        std::cout << "List: ";
        while (temp)
        {
            std::cout << temp->value << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    void getHead()
    {
        std::cout << "Head: " << this->head->value << std::endl;
    }
    void getTail()
    {
        std::cout << "Tail: " << this->tail->value << std::endl;
    }
    void getLength()
    {
        std::cout << "Length: " << this->length << std::endl;
    }
};

int main()
{
    LinkedList *myLinkedList = new LinkedList(2);
    myLinkedList->append(3);

    myLinkedList->prepend(1);

    myLinkedList->printList();
    return 0;
}