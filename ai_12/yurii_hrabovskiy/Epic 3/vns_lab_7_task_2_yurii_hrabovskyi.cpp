#include <iostream>
#include <string>
using namespace std;

int min_e(int array[], int size)
{
    int min = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}


int min_e(string str)
{
    int shortest = str.size(), current = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            current++; 
        }
        else 
        {
            if (current > 0 && current < shortest)
            {
                shortest = current;
            }

            current = 0;
        }
    }
    if (current > 0 && current < shortest)
    {
        shortest = current;
    }
    if (current==0)
    {
        shortest = current;
    }

    return shortest;
}


int main()
{
    int n;

    cout << "Введіть розмір масиву: ";
    cin >> n;


    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введіть елемент масиву: ";
        cin >> array[i];
    }
    
    int min = min_e(array, n);

    cout << "Найменше значення в масиві: " << min << endl;

    
    
    string str;

    cout << "Введіть рядок: ";
    
    cin.ignore();
    getline(cin, str);

    int shortest = min_e(str);

    cout << "Найкоротше слово в рядку містить " << shortest << " букв";

    return 0;
}