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
		if (this->length == 0)
		{
			this->front = newNode;
			this->back = newNode;
			this->length = 1;
		}
		else
		{
			this->back->next = newNode;
			this->back = newNode;
			this->length++;
		}
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
	void printQ()
	{
		Node *temp = this->front;
		while (temp)
		{
			std::cout << temp->value << ", ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	void getFront()
	{
		std::cout << "Front: " << this->front->value << std::endl;
	}
	void getBack()
	{
		std::cout << "Back: " << this->back->value << std::endl;
	}
	void getLength()
	{
		std::cout << "Length: " << this->length << std::endl;
	}
};

int main()
{
	Queue *myQ = new Queue(7);
	myQ->getFront();
	myQ->getBack();
	myQ->getLength();
	myQ->printQ();
	return 0;
}

// push, pop, size, front, back
