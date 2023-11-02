// smart pointers


#include <iostream>
using namespace std;


// simple implementation of smart pointer
template <typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr)
	{
		this->ptr = ptr;
		cout << "Inside Constructor\n";
	}

	~SmartPointer()
	{
		delete ptr;
		cout << "Inside Destructor\n";
	}


	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr; // обычный указатель на тип T
};


int main()
{
	/*
	int* ptr = new int(5);

	cout << ptr << '\n';
	cout << *ptr << '\n';
	*/

	// smart pointer for type: int
	SmartPointer<int> smart_pointer = new int(5);
	
	cout << *smart_pointer << '\n';

	*smart_pointer = 20;
	cout << *smart_pointer << '\n';


	//smart pointer for type: float


	return 0;
}