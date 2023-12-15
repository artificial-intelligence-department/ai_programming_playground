#include <iostream>
using namespace std;

int main() 
{
    int size1 = 10;
    int arr[size1]; 

    for(int i = 0; i < size1; i++) 
    {
        arr[i] = std::rand() % 10;  
        cout << arr[i] << "  ";
    }

    cout << endl;

    for (int i = 0; i < size1; i++) 
    {
        if (arr[i] == 0) // цикл для видалення першого нуля в масиві
        {
            for (int j = i; j < size1 - 1; j++) 
            {
                arr[j] = arr[j + 1];
            }
            size1--;
            break;   
        }
    }

    cout << "Масив після видалення: ";
    for (int i = 0; i < size1; i++) 
    {
        cout << arr[i] << "  ";
    }

    cout << endl;

    for (int i = 0; i < size1; i++) 
    {
        if (i % 2 == 1 && i != 0) 
        {
            arr [i+1] =  arr[i-1] + 2;
        }
    }



    cout << "Масив після M[I-1]+2:  ";
    for (int i = 0; i < size1; i++) 
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
