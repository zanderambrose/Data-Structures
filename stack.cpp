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
    int pop()
    {
        if (this->height == 0)
            return INT_MIN;
        StackNode *temp = this->top;
        int poppedValue = temp->value;
        this->top = temp->next;
        delete temp;
        this->height--;
        return poppedValue;
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
    Stack *stack = new Stack(2);
    stack->printStack();
    stack->push(1);
    stack->printStack();
    stack->getHeight();
    stack->getTop();
    return 0;
}