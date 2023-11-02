#include <iostream>
#include <vector>

// in my experiments
#include "point2d.h"


using namespace std;


/*
* Библиотека стандартаных шаблонов (STL)
*
* Векторы
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
    // double a = static_cast<double>('1');

    // cout << "a = " << a << '\n';

    vector<int> v = {10, 20, 5, 3};
    print_vector_elems(v);


    cout << '\n';


    // .push_back - add elems at the end of vector
    cout << ".push back method: \n";
    v.push_back(100);
    v.push_back(200);
    print_vector_elems(v);


    cout << "\n";

    // .capacity() - вместимость вектора
    cout << "v.capacity() = " << v.capacity() << '\n';


    // 
    v.reserve(100); // устанавливаем вместивость на 100 элементов
    cout << "v.capacity() = " << v.capacity() << '\n';


    // .shrink_to_fit() - освобождает неиспользуемую память, уменьшая вместимость вектора до .size() размера
    v.shrink_to_fit();
    cout << "v.capacity() = " << v.capacity() << '\n';


    cout << '\n';

    // создание вектора заданного размера и заполнение его опредедёнными значениями
    vector<int> b(10, 3);
    print_vector_elems(b);
    cout << "b.capacity() = " << b.capacity() << '\n';

    cout << '\n';

    // check, is vector empty
    cout << "check v.empty: " << v.empty() << '\n';
    cout << "v.capacity() = " << v.capacity() << '\n';

    
    cout << '\n';

    // resize vector 
    print_vector_elems(v);
    v.resize(20, -1);
    print_vector_elems(v);


    // обсуждение данных методов перенесено в следующий урок т.к. нужно понимание итераторов
    // вставка данных в вектор
    // v.insert(10);
    // print_vector_elems(v);


    // удаление данных из вектора
    // v.erase();




    // MY EXPERIMENTS
    cout << '\n';
    cout << "MY EXPERIMENTS\n";
    
    Point2D<int> p1 = {1, 2};
    cout << "p1.x = " << p1.x << '\n';
    cout << "p1.y = " << p1.y << '\n';

    vector<Point2D<int>> vector_p2d(
        {
            {1, 2},
            {3, 4},
            {5, 6},
            {7, 8}
        }
    );

    cout << "Print points inside vector:\n";
    for (auto elem : vector_p2d)
    {
        cout << "point.x = " << elem.x << '\n';
        cout << "point.y = " << elem.y << '\n';
        cout << '\n';
    }


    return 0;
}