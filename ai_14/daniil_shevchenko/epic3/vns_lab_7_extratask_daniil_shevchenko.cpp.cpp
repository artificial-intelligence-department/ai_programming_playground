#include <iostream>

using namespace std;
int* arrmod(int array[],int size)
{
    int* modarray = new int[size];
    if (array[0] % 2 == 0)
    {
        int step = array[0] % size;
        for (int i = size - 1, j = 0; i >= 0; i--)
        {
            if (i >= step)
            {
                modarray[i - step] = array[i];
            }
            else
            {
                modarray[size - 1 - j] = array[i];
                j++;
            }
        }
    }
    if (array[0] % 2 != 0)
    {
        int step = array[size - 1] % size;
        for (int i = 0, j = 0; i <= size - 1; i++)
        {
            if ((size - i - 1) >= step)
            {
                modarray[i + step] = array[i];
            }
            else
            {
                modarray[j] = array[i];
                j++;
            }
        }
    }
    return modarray;
}

int main()
{
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arrmod(array,size)[i] << " ";
    }
}

