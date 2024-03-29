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
    void deleteFirst()
    {
        if (this->length == 0)
            return;
        if (this->length == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->head = this->head->next;
        }
        this->length--;
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
    Node *get(int index)
    {
        if (index < 0 || index >= this->length)
            return nullptr;
        int currIndex = 0;
        Node *temp = this->head;
        while (temp)
        {
            if (currIndex == index)
                return temp;
            currIndex++;
            temp = temp->next;
        }
        return nullptr;
    }
    bool set(int value, int index)
    {
        if (index < 0 || index > this->length)
        {
            return false;
        }
        else if (index == 0)
        {
            this->head->value = value;
            return true;
        }
        else
        {
            Node *temp = this->head;
            for (int i = 1; i <= index; i++)
            {
                temp = temp->next;
            }
            temp->value = value;
            return true;
        }
    }
    bool insert(int value, int index)
    {
        if (index < 0 || index > this->length)
        {
            return false;
        }
        else if (index == 0)
        {
            this->prepend(value);
            return true;
        }
        else if (index == length)
        {
            this->append(value);
            return true;
        }
        else
        {
            Node *newNode = new Node(value);
            Node *temp = this->head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            this->length++;
            return true;
        }
    }
    void deleteNode(int index)
    {
        if (index < 0 || index >= this->length)
        {
            return;
        }
        else if (index == 0)
        {
            return this->deleteFirst();
        }
        else if (index == this->length - 1)
        {
            return this->deleteLast();
        }
        else
        {
            Node *temp = this->head->next;
            Node *prev = this->head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
                prev = prev->next;
            }
            prev->next = temp->next;
            delete temp;
            length--;
        }
    }
    void reverse()
    {
        Node *current = this->head;
        this->head = this->tail;
        this->tail = current;
        Node *next = current->next;
        Node *previous = nullptr;
        for (int i = 0; i < this->length; i++)
        {
            current->next = previous;
            previous = current;
            current = next;
            if (next->next)
            {

                next = next->next;
            }
        }
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
    LinkedList *myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);

    myLinkedList->getHead();
    myLinkedList->getTail();

    myLinkedList->printList();

    myLinkedList->reverse();
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();

    return 0;
}