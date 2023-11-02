#include<iostream>
#include <forward_list>

using namespace std;


/*
* Библиотека стандартных шаблонов STL
*
* forward_list - реализация односвязного списка
* 
* 
*/


template<typename T>
void print_flist_elems(T const& l)
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
	forward_list<int> l1 = { 1, 2, 3 };
	print_flist_elems(l1);

	//l1.clear();
	//print_flist_elems(l1);


	// only push_front, pop_front
	l1.push_front(10);
	print_flist_elems(l1);
	l1.pop_front();
	print_flist_elems(l1);


	// there isn't push_back, pop_back
	// because forward list

	// if you need push_back, pop_back - maybe structure list
	// is more prefered








	return 0;
}