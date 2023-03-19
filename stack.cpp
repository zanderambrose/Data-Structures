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
    void push(int value)
    {
        StackNode *newNode = new StackNode(value);
        newNode->next = this->top;
        this->top = newNode;
        this->height++;
    }
    void getTop()
    {
        std::cout << "Top of stack: " << this->top->value << std::endl;
    }
    void getHeight()
    {
        std::cout << "Height of stack: " << this->height << std::endl;
    }
    void printStack()
    {
        StackNode *temp = this->top;
        while (temp)
        {
            std::cout << temp->value << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack *stack = new Stack(1);
    stack->getHeight();
    stack->getTop();
    stack->printStack();
    return 0;
}