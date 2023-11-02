// Реализация структуры данных: 
// Односвязный список

#include <iostream>
#include <string>
using namespace std;


template <typename T>
class List
{
public:
	List();
	~List();

private:


	template <typename T>
	class Node
	{
	public:
		Node* pNext; //pointer Next - указатель на следующий элемент
		T data;

		Node(T data=T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;
};

template <typename T>
List<T>::List()
{
}

template <typename T>
List<T>::~List()
{
}


int main()
{
	cout << "LinkedList implementation;\n";
	return 0;
}