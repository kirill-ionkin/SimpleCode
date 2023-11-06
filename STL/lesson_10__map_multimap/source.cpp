#include <iostream>
#include <string>
#include <vector>
#include <map> // needed library
using namespace std;


/*
/ Библиотека стандартаных шаблонов (STL)
/ Ассоциативные упорядоченные контейнеры пар - ключ, значение
/
/ map, multimap
/
*/


int main()
{
    // block MAP
    // создание пары
    pair<int, string> p(1, "Product1");
    cout << "p.first = " << p.first << '\n';
    cout << "p.second = " << p.second << '\n';


    // создание map
    map<int, string> myMap;
    

    // добавление элементов
    myMap.insert(p); // insert требует pair
    myMap.insert(make_pair(2, "Product2")); // make_pair
    
    myMap.emplace(3, "Product3"); // удобно т.к. не нужно pair создавать
    myMap[4] = "Product4"; // удобный способ добавления
    myMap.at(4) = "Product4_copy"; // .at проверяет наличие ключа, иначе исключение, а не добавление новой пары ключ значение
    try
    {
        myMap.at(100);
    }
    catch (...)
    {
        cout << "Error .at\n";
    }
        


    // попытка добавить дубликат не получится
    myMap.emplace(3, "Product3_copy"); 
    cout << "myMap[3] = " << myMap[3] << '\n';


    // результат добавление возвращается функцией
    auto res = myMap.emplace(3, "Product3_copy");


    // поиск по ключу
    auto it = myMap.find(2); 
    if (it == myMap.end())
        cout << "Not found\n";
    else
        cout << (*it).first << " " << (*it).second << '\n';

    auto it2 = myMap.find(120); 
    if (it2 == myMap.end())
        cout << "Not found\n";
    else
        cout << (*it2).first << " " << (*it2).second << '\n';





    // BLOCK MULTIMAP - может хранить дублирующиеся ключи и их значения
    multimap<int, string> mul_map;
    mul_map.emplace(1, "Prod1");
    mul_map.emplace(1, "Prod1_copy");

    

}