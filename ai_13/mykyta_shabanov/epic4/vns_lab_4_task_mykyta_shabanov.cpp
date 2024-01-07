#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void DestroyElement(int index, int arr[], int &size)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
}

void AddAfterEven(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        if(i > 3)
            arr[i] = arr[i - 1];
        else
        {
            arr[i] = arr[i-1] + 2;
            return;
        }
    }
    
}

int main() 
{
    random_device rd;  
    mt19937 gen(rd()); 

    uniform_int_distribution<int> distr(1, 20);

    int arrSize = distr(gen);
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = distr(gen);
        cout << arr[i] << " ";
    }
    cout << endl;

    int deleteThisElement = 3;
    DestroyElement(deleteThisElement, arr, arrSize);

    AddAfterEven(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
