#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int Size = 10;
    int arr[Size];

    srand(time(nullptr));
    for (int i = 0; i < Size; i++) 
    {
        arr[i] = rand() % 100 + 1; 
    }

    cout << "Array: ";
    for (int i = 0; i < Size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index;
    cout << "Enter index to remove: ";
    cin >> index;
    if (index >= 0 && index < Size) 
    {
        for (int i = index - 1; i < Size - 1; i++) 
        {
            arr[i] = arr[i + 1];
        }
    } else {
        cout << "Wrong number" << endl;
        return 0;
    }

    cout << "New array: ";
    for (int i = 0; i < Size - 1; i++) 
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < Size - 1; i++) 
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = Size - 1; j > i + 1; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = arr[i] + 2;
            break;
        }
    }
    cout << "Array in the end: ";
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
