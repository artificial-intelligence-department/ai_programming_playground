#include<iostream>
using namespace std;
int main()
{
    cout << "----------------Max/Min Array----------------" << endl;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arrayNumber[size];
    int max = 0;
    int min = 0;
    for(int i = 0; i < size; i++)
    {
        int element;
        cout << ": ";
        cin >> element;
        arrayNumber[i] = element;
    }
    for(int i = 0; i < size; i++)
    {
        if(arrayNumber[i] > max)
        {
            max = arrayNumber[i];
        }
    }
    cout << "Max: " << max << endl;
    for(int i = 0; i < size; i++)
    {
        if(arrayNumber[i] < max)
        {
            max = arrayNumber[i];
            min = arrayNumber[i];
        }
    }
    cout << "Min: " << min << endl;
}