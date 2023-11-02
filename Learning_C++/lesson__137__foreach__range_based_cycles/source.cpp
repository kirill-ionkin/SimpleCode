#include <iostream>
#include <vector>
#include <list>
using namespace std;


/*
* Цикл for each - deprecated
* range based циклы - это то, что нужно
*
*
* Syntax
* for (type variableName : arrayName) {
*     code block to be executed
* }
*
*/


int main()
{
    // for each цикл - deprecated


    // range-based циклы
    int arr[] = {1,2,3,4,5};

    for (int elem : arr)
        cout << elem << " ";

    cout << '\n';

    // удобно использовать auto
    for (auto elem : arr)
        cout << elem << " ";

    cout << '\n';
    
    // данные при каждой итерации копируются(передаются по значению), а не ссылаются
    for (auto elem : arr)
        elem = -1;
    
    for (auto elem : arr) // массив arr не изменился
        cout << elem << " ";

    cout << '\n';
    

    // но можно передавать значения по ссылке и изменять значения массива
    for (auto &elem : arr)
        elem = -1;
    
    for (auto elem : arr)
        cout << elem;

    cout << '\n';


    // получение данных по ссылке, но с защитой от изменений
    for (const auto &elem : arr)
        cout << elem << ' ';

    cout << '\n';




    // STL
    list<int> l = {1, 2, 3, 4, 5};
    for (auto elem : l)
    {
        cout << elem << " ";
    }



    return 0;
}