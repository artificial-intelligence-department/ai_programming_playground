//1) Сформувати одновимірний масив цілих чисел, використовуючи генератор
//випадкових чисел.
//2) Роздрукувати отриманий масив.
//
//3) Знищити з масиву всі елементи, які співпадають з його мінімальним
//значенням.
//4) Додати на початок масиву 3 елементи зі значенням, яке дорівнює середньому
//арифметичному масиву.
//5) Роздрукувати отриманий масив.


#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
    const int n = 10;
    int array[n] = {};

    int lb = 1, ub = 100;
    for (int i = 0; i < n; i++)
        array[i] = (rand() % (ub - lb + 1)) + lb;

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    int min = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    cout << endl;
    cout << min << endl;
    for (int i = 0; i < n; i++)
    {
        if (min == array[i])
        {
            for (int j = i; j < n - 1; j++)
            {
                array[j] = array[j + 1];
            }
        }
    }   
    array[n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    int avg = sum / n;

    const int n2 = 13;
    int array2[n2] = {};

    array2[0] = array2[1] = array2[2] = avg;
    for (int i = 3; i < n2; i++) {
        array2[i] = array[i - 3];
    }

    for (int i = 0; i < n2; i++)
    {
        cout << array2[i] << " ";
    }

}