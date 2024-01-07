#include <iostream>
using namespace std;

int main()
{   
    int arraySize=0;
    int x, y, z;
    cin >> arraySize;
    int arr[arraySize];
    for (int i=0; i<arraySize; i++)
    {
        cin>>arr[i];
    }
    cin>> x >> y >>z;
    for (int i=0; i<arraySize; i++)
        if (arr[i]==x || arr[i]==y || arr[i]==z)
        {
            for (int k = i; k < arraySize - 1; k++)
            {
                arr[k] = arr[k + 1];
            }
            arraySize--;
            i--;
        }
    
    if (arraySize!=0)
    {
        int newSize = arraySize - 1;
        int newArr[newSize];
        
        cout<< newSize << endl;
        for (int i = 0; i < arraySize; i++) 
        {
            newArr[i] = arr[i] + arr[i + 1];
        }
        
        for (int i = 0; i < newSize; i++)
        {
            cout << newArr[i] << " ";
        }
    }
    else 
    {
        cout << 0;
    }
    return 0;
}
