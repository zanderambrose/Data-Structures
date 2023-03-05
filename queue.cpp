#include <iostream>


template <typename T>
class Queue{
	private:
		T item[10];	
		T head;
		T tail;

	public:
		void enqueue();
		void dequeue();
		void push();
		void pop();
		void empty();
		void size();


};


int main(){
	Queue<int> myQ;
	return 0;
}


// push, pop, size, front, back
