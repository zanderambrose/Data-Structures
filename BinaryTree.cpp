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
    BinarySearchTree()
    {
        this->root = nullptr;
    }
    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (this->root == nullptr)
        {
            this->root = newNode;
            return true;
        }
        Node *temp = this->root;
        while (temp)
        {
            if (temp->value == newNode->value)
                return false;
            if (value < temp->value)
            {
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newNode;
                    return true;
                }
            }
            else
            {
                if (temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newNode;
                    return true;
                }
            }
        }
    }
};

int main()
{
    return 0;
}