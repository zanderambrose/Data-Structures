#include <iostream>
#include <string>

class Node
{
public:
    int value;
    std::string key;
    Node *next;

    Node(std::string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];
};