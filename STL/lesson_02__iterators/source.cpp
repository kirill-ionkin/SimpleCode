#include <iostream>
#include <vector>
using namespace std;

/*
* Библиотека стандартаных шаблонов (STL)
*
* Итераторы
*/


// print vector elems
void print_vector_elems(const vector<int>& v)
{   
    if (!v.size())
        cout << "Vector is empty\n";
    else
    {
        cout << "Vector elems:\n";
        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << '\t';
        cout << '\n';
    }
}


int main()
{
    int arr[] = {2, 6, 9};

    // получение доступа к элементам массива(не динамический)
    cout << arr[0] << '\t' << arr[1] << '\t' << arr[2] << '\n';
    cout << *arr << '\t' << *(arr + 1) << '\t' << *(arr + 2) << '\n';


    vector<int> v = {1, 22, 33, 45, 10, 23};
    print_vector_elems(v);

    // получение доступа к элементам вектора(динамический) с помощью обычной индексации - НО оператор [] не увсех контейнеров переопределён
    cout << v[0] << '\t' << v[1] << '\n';


    // получение доступа к элементам вектора(динамический) с помощью итератора
    
    vector<int>::iterator it; // создание итератора it типа vector<int>::iterator

    // чтобы перебрать элементы вектора, нужно связать итератор с контейнером
    it = v.begin(); // даём доступ к 1-ому элементу вектора
    cout << *it << '\n';

    // попробуем изменить данные с помощью итератора
    *it = 1000;
    print_vector_elems(v);


    // итераторы поддерживают арифметику указателей
    it++;
    cout << *it << '\n';

    it--;
    it+= 2;
    cout << *it << '\n';


    // можно в цикле итерироваться по вектору с помощью итератора
    for (vector<int>::iterator it2 = v.begin(); it2 != v.end(); ++it2)
    {
        cout << *it2 << '\t';
    }

    cout << '\n';

    // итерирование с конца в начало
    for (vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); ++it2)
    {
        cout << *it2 << '\t';
    }

    cout << '\n';


    // существуют разные типы итераторов

    // const итератор
    for (vector<int>::const_iterator it3 = v.begin(); it3 != v.end(); ++it3)
    {
        cout << *it3 << '\t';

        // *it3 = new_value! // Ошибка! Менять данные при использовании const итератора нельзя
    }



    cout << '\n';


    // не все итераторы являются итераторами произвольного доступа
    // advance
    vector<int>::iterator it4 = v.begin();
    advance(it4, 3);  // подвинуть на 3 поцизиции относительно текущей

    cout << *it4 << '\n';


    cout << '\n';


    // insert - insert elem in vector
    print_vector_elems(v);

    vector<int>::iterator it5 = v.begin();
    cout << "insert elem  99999 in vector\n";
    v.insert(it5, 99999); // insert elem in vector 
    print_vector_elems(v);


    cout << '\n';


    // erase - delete elem from vector
    print_vector_elems(v);
    cout << "erase\n";
    vector<int>::iterator it6 = v.begin();
    v.erase(it6);
    print_vector_elems(v);
    v.erase(it6, it6 + 1); // equal as v.erase(it6);
    print_vector_elems(v);


    return 0;
}