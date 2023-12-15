//Завдання 6. Написати програму, яка виводить на екран — таку
//фігуру :
//Ширина й висота фігури запитуються в користувача
//як додатне, непарне число.


#include <iostream>

using namespace std;
int main()
{
    int size;
    cout << "Enter the number (positive odd number): " ;
    cin >> size;
    if (size > 0 && (size % 2) != 0)
    {
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                if ((y == x) || (y == size / 2) || (x == size / 2) || (y + x == size - 1))
                {
                    cout << " * ";
                }
                else cout << "   ";
            }
            cout << endl;
        }
        return 0;
    }
}