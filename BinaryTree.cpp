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
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (this->root == nullptr)
        {
            this->root = newNode;
            return;
        }
        Node *temp = this->root;
        while (temp)
        {
            if (temp->value == newNode->value)
                return;
            if (value < temp->value)
            {
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newNode;
                    break;
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
                    break;
                }
            }
        }
    }
};

int main()
{
    return 0;
}