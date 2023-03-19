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
        if (this->length == 0)
        {
            this->head = newNode;
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
            this->head->previous = newNode;
            this->head = newNode;
        }
        this->length++;
    }
    void deleteLast()
    {
        if (this->length == 0)
        {
            return;
        }
        Node *temp = this->tail;
        if (this->length == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->tail = this->tail->previous;
            this->tail->next = nullptr;
        }
        delete temp;
        this->length--;
    }
    void deleteFirst()
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
            this->head = this->head->next;
            this->head->previous = nullptr;
        }
        delete temp;
        this->length--;
    }
    Node *get(int index)
    {
        if (this->length == 0 || index < 0 || index >= this->length)
        {
            return nullptr;
        }
        Node *temp = this->head;
        if (index < this->length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = this->tail;
            for (int i = this->length - 1; i > index; i--)
            {
                temp = temp->previous;
            }
        }
        // std::cout << temp->value << std::endl;
        return temp;
    }
    bool set(int index, int value)
    {
        if (index < 0 || index >= this->length)
        {
            return false;
        }
        Node *node = this->get(index);
        node->value = value;
        return true;
    }
    bool insert(int index, int value)
    {
        if (index < 0 || index > this->length + 1)
        {
            return false;
        }
        if (index == this->length)
        {
            this->append(value);
            return true;
        }
        if (index == 0)
        {
            this->prepend(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = this->get(index - 1);
        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
        this->length++;
        return true;
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
    void getLength()
    {
        std::cout << "Dll Length: " << this->length << std::endl;
    }
};

int main()
{
    DoublyLinkedList *myDll = new DoublyLinkedList(11);
    myDll->append(3);
    myDll->append(23);
    myDll->append(7);

    myDll->printList();

    myDll->insert(10, 69);
    myDll->printList();
}