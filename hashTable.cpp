#include <iostream>
#include <string>
#include <vector>

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
        // std::cout << "Hash is: " << hash << std::endl;
        return hash;
    }
    void set(std::string key, int value)
    {
        int index = this->hash(key);
        Node *newNode = new Node(key, value);
        if (this->dataMap[index] == nullptr)
        {
            this->dataMap[index] = newNode;
        }
        else
        {
            Node *temp = this->dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    Node *get(std::string key)
    {
        int index = this->hash(key);
        Node *temp = this->dataMap[index];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                // std::cout << "Value is: " << temp->value << std::endl;
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }
    std::vector<std::string> keys()
    {
        std::vector<std::string> returnVector;
        for (int i = 0; i < SIZE; i++)
        {
            Node *temp = this->dataMap[i];
            while (temp)
            {
                returnVector.push_back(temp->key);
                temp = temp->next;
            }
        }
        for (std::string key : returnVector)
        {
            std::cout << key << ", ";
        }
        std::cout << std::endl;
        return returnVector;
    }
    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            std::cout << i << ":" << std::endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    std::cout << "   {" << temp->key << ", " << temp->value << "}" << std::endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main()
{
    HashTable *hash = new HashTable();
    hash->set("nails", 100);
    hash->set("tile", 50);
    hash->set("lumber", 80);

    hash->set("bolts", 200);
    hash->set("screws", 140);

    // hash->get("tile");

    // hash->printTable();
    hash->keys();
    return 0;
}