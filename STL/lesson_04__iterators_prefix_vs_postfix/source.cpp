#include<iostream>
#include<list> // необходиый header
#include<vector>

using namespace std;


/*
* Библиотека стандартных шаблонов STL
* 
* В чём разница между it++ и ++it
* 
*/

template<typename T>
void print_list_elems(T const& l)
{
	auto it = l.cbegin(); // const begin

	while (it != l.cend()) // const end
	{
		cout << *it << ' ';
		++it;
	}
	cout << '\n';
}


int main()
{
	// ++it и it++ имеют разный приоритет

	int a = 5;
	cout << a++ << '\n'; // 5, a = 6
	
	a = 5;
	cout << ++a << '\n'; // 6, a = 6


	list<int>::iterator it;

	it++; // посмотрим на реализацию с помощью IDE

	++it; // посмотрим на реализацию с помощью IDE


	return 0;
}
