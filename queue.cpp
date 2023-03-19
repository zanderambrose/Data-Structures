#include <iostream>

class Node
{

public:
	int value;
	Node *next;

	Node(int value)
	{
		this->value = value;
		this->next = nullptr;
	}
};

class Queue
{
private:
	int length;
	Node *front;
	Node *back;

public:
	Queue(int value)
	{
		Node *newNode = new Node(value);
		this->front = newNode;
		this->back = newNode;
		this->length = 1;
	}
	void enqueue(int value)
	{
		Node *newNode = new Node(value);
		this->back->next = newNode;
		this->back = newNode;
		this->length++;
	}
	int dequeue()
	{
		if (this->length <= 0)
			return INT_MIN;
		int frontValue = this->front->value;
		Node *tempFront = this->front;
		this->front = tempFront->next;
		this->length--;
		delete tempFront;
		return frontValue;
	}
};

int main()
{
	Queue myQ(1);
	return 0;
}

// push, pop, size, front, back
