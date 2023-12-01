#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
     int size ;
     cin>>size;
    int arr[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    int index;
    cout << "Enter the index of the element to delete: ";
    cin >> index;
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = size - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = arr[i] + 2;
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


