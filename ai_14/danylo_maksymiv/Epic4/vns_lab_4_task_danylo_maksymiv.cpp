#include <iostream>
#include <cstdlib>

using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
}

void random(int a[], int b) 
{
    for (int i = 0; i < b; i++) 
    {
        a[i] = rand() % 100;
    }
}

void del(int arr[], int& size, int k) 
{
    for (int i = k; i < size - 1; ++i) 
    {
        arr[i] = arr[i + 1];
    }
    --size;
}

void pluszero(int*& arr, int& size) 
{
    int evenCount = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            evenCount++;
        }
    }

    int newSize = size + evenCount;
    int* newArr = new int[newSize];

    for (int i = 0, j = 0; i < size; ++i) 
    {
        newArr[j++] = arr[i];
        if (arr[i] % 2 == 0) 
        {
            newArr[j++] = 0;
        }
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}

int main() 
{
    int size;
    cout << "Enter size:" << endl;
    cin >> size;
    int* arr = new int[size];
    int k;
    
    cout << "Here is random array:" << endl;
    random(arr, size);
    print(arr, size);

    cout << endl << "Enter K" << endl;
    cin >> k;

    del(arr, size, k - 1);
    cout << "Here is array without k-element:" << endl;
    print(arr, size);

    cout << endl << "Array when added zeros after each even element:" << endl;
    pluszero(arr, size);
    print(arr, size);
    delete[] arr;

}
