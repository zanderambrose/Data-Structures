#include<iostream>

template <typename T>
class LinkedList{
	public:
		LinkedList(T value){
			this->value = value;	
		}
		T value;
};

int main(){
	LinkedList<int> myLl(10);
	std::cout << "My LL value is: " << myLl.value << std::endl;
	//std::cout << "Hello linked list." << std::endl;
	return 0;
}
