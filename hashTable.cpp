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

public:
    int hash(std::string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        std::cout << "Hash is: " << hash << std::endl;
        return hash;
    }
};

int main()
{
    HashTable hash;
    hash.hash("father");
    return 0;
}