#include<iostream>
#include<list> // необходиый header
#include<vector>

using namespace std;


/*
* Библиотека стандартных шаблонов STL
*
* list - реализация 2связного списка(head, tail)
* 
* list - удаление, добавление элемента выполняется быстро в отличие от динамического массива
* 
* у list нет реализации итератора произвольного доступа
* 
*/

template<typename T>
void print_list_elems(T const &l)
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
	list<int> l1 = { 1, 2, 3 };
	print_list_elems(l1);


	// добавление элемента в конец списка
	l1.push_back(-100);

	// добавдение элемента в начало списка
	l1.push_front(100);


	list<int>::iterator it = l1.begin();
	print_list_elems(l1);

	// sort list elems
	l1.sort();
	print_list_elems(l1);

		
	// удаление с конца и начала
	l1.pop_back();
	print_list_elems(l1);
	l1.pop_front();
	print_list_elems(l1);


	// size
	cout << "l1.size() = " << l1.size() << '\n';

	
	// удаление подряд идущие дублкиаты
	list<int> l2 = { 1, 1, 1, 2, 3, 4, 1 };
	l2.unique();
	print_list_elems(l2);


	// реверс порядка элементов 
	l2.reverse();
	print_list_elems(l2);


	// clear all elems
	l2.clear();
	cout << "l2.size() = " << l2.size() << '\n';


	// вставка элемента в list
	auto it2 = l2.begin();
	l2.insert(it2, 111);
	print_list_elems(l2);

	// l2.insert(++it2, 112); // not possible!
	// print_list_elems(l2);

	// чтобы сдвигать итератор, есть метод advance
	auto it3 = l2.begin();
	advance(it3, 1); // сдвигаем итератор на n позиций
	l2.insert(it3, 112);
	print_list_elems(l2);

	cout << '\n';

	// удаление с помощью erase
	//l2.erase(it3);
	//print_list_elems(l2);

	
	// remove  - удаление конкретного элемента из list
	l2.remove(111);
	print_list_elems(l2);
	
	// assign - чистка и заполнение list значениями
	l2.assign(3, 10); // 3 раза число 10
	print_list_elems(l2);


	// копирование из одного list в другой list
	// с помощью assign
	list<int> l3;
	l3.assign(l2.begin(), l2.end());
	print_list_elems(l3);



	return 0;
}