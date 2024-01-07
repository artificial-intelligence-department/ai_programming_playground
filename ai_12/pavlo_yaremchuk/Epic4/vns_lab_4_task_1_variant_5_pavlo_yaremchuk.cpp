#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int N = 100;
    int a[N];
    int l;
    cout << "Введіть реальну довжину масиву (не більшу за 100): ";
    cin >> l;
    cout << "Масив розміром " << l << ": ";
    srand(time(0));
    for (int i = 0; i < l; ++i)
    {
        int random = rand() % 100;
        a[i] = random;
        cout << a[i] << " ";
    }
    
    int j = 0;
    for (int i = 0; i < l; ++i)
    {
        if (a[i] % 7 != 0)
        {
            a[j] = a[i];
            ++j;
        }
    }
    
    cout << endl << "Масив після знищення елементів, кратних 7: ";
    for (int i = 0; i < j; ++i)
    {
        cout << a[i] << " ";
    }

    for (int i = 0; i < j; ++i)
    {
        if (a[i] % 2 != 0)
        {
            for (int k = j; k > i; --k)
            {
                a[k] = a[k - 1];
            }
            a[i + 1] = 0;
            ++j;
        }
    }

    cout << endl << "Масив після додавання після кожного непарного елемента масиву елемент зі значенням 0: ";
    for (int i = 0; i < j; ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}