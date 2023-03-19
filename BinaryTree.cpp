#include <iostream>

class Node
{
public:
    int value;
    Node *right;
    Node *left;

    Node(int value)
    {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree(int value)
    {
        Node *newNode = new Node(value);
        this->root = newNode;
    }
};

int main()
{
    return 0;
}