// smart pointers


#include <iostream>
#include <string>
#include <memory>

using namespace std;


/*
* smart_pointers:
* auto_ptr
* unique_ptr
* shared_ptr
* 
* weak_ptr
*/




// simple implementation of smart pointer
template <typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
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
	SmartPointer<int> sp1 = new int(5);

	SmartPointer<int> sp2 = sp1;

	// 2ое освобождение памяти!!! - ошибка компиляции



	// Как такие проблемы решать?
	// <memory> - в помощь!


	return 0;
}