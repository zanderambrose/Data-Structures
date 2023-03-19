#include <iostream>

class StackNode
{
public:
    int value;
    StackNode *next;
    StackNode(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack
{
private:
    int height;
    StackNode *top;

public:
    Stack(int value)
    {
        StackNode *newNode = new StackNode(value);
        this->top = newNode;
        this->height = 1;
    }
};

int main()
{
    return 0;
}