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

int main()
{
    return 0;
}