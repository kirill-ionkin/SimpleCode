#include <iostream>
#include <vector>
#include <set> // needed include


using namespace std;


/*
* Библиотека стандартаных шаблонов (STL)
*
* упорядоченные ассоциативные контейнеры
* основаны на структуре данных: бинарное дерево
*
* set, multiset
*
* set - хранит только уникальные элементы
* multiset - может хранить одинаковые элементы в отличие от set
*/


int main()
{

    /*
    / set
    */
    cout << "SET BLOCK\n";

    set<int> s;

    // add elems to set - insert
    s.insert(5);
    s.insert(5);
    s.insert(2);
    s.insert(10);
    s.insert(7);


    for (auto &elem : s)
    {
        cout << elem << ' ';
    }
    cout << '\n';
    

    cout << "add random generated numbers\n";
    // insert random generated numbers
    for (int i = 0; i < 20; i++)
    {
        s.insert(rand() % 10);
    }


    for (auto elem : s)
        cout << elem << ' ';
    cout << '\n';


    // поиск, есть ли тот или иной элемент в set
    set<int>::iterator it = s.find(10);

    if (it == s.end())
        cout << "not found 10\n";
    else
        cout << "found 10\n";

    
    if (s.find(11) == s.end())
        cout << "not found 11\n";
    else
        cout << "find 11\n";


    // удаление элемента из set
    cout << "erase 5 from set s\n";
    auto res = s.erase(5);
    cout << res << '\n';
    for (auto elem : s)
        cout << elem << ' ';
    cout << '\n';


    // удаление не существующего эл-та - ничего не происходит
    cout << "erase 1000 from set s\n";
    res = s.erase(1000);
    cout << res << '\n';

    // insert также возвращает результат вставки
    auto res_insert = s.insert(-1000);
    


    /*
    / multiset
    */
    cout << "MULTISET BLOCK\n";


    multiset<int> ms = {0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5};

    for (auto elem : ms)
        cout << elem << ' ';
    cout << '\n';

    ms.insert(10);
    ms.insert(10);

    for (auto elem : ms)
        cout << elem << ' ';
    cout << '\n';


    // так как могут быть дупликаты, то можно искать начало и конец  элементов
    multiset<int>::iterator it1_begin = ms.lower_bound(1); // 1ая единица - указатель на неё
    multiset<int>::iterator it1_end = ms.upper_bound(1); // следующий элемент после последней единицы (учитывая упорядоченность элементов) - указатель
    cout << "lower bound 1: " << *it1_begin << '\n';
    cout << "upper bound 1: " << *it1_end << '\n';


    // equal-range - граница lower, upper bounds поиска 1
    auto range = ms.equal_range(1);
    




    // Мои эксперименты

    // 1. Помещение в vector обьектов моего класса - необходимо реализовать оператор < т.к. set упорядоченная стуктура(бинарное дерево)
    cout << '\n';
    cout << "MY EXPERIMENTS\n";
    struct Entry
    {
        Entry(int time, double val) : time_s(time), val(val) {}

        int time_s;
        double val;

        bool operator<(const Entry &other) const
        {
            return time_s < other.time_s;
        }
    };

    set<Entry> set_entries = {Entry(10, 0.2) , Entry(20, 0.3) , Entry(30, 0.4)};
    set<Entry>::iterator it2 = set_entries.begin();
    cout << it2->time_s << ' ' << it2->val << '\n';


}