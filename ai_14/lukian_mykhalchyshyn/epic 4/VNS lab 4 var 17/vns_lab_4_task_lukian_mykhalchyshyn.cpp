#include <iostream>


using namespace std;

int main()
{   
    int N, K;

    cout << "Введіть розмір масиву: ";
    cin >> N;
    
    cout << "введіть значення К: ";
    cin >> K;

    int* arr = new int [N];
    for (int i=0; i<N; i++)
    {
        cout << "Введіть " << i+1 << " елементи масиву: ";
        cin >> arr[i];
    }
        
    int temp = K-1;
    for (int i=0; i<N; i++)
    {
        cout  << arr[temp] << " ";
        temp++;
        if(temp == N)
        {
            temp = 0;
        } 
    }

    int* arr1 = new int[N+2];
    temp = K-1;
    for (int i=0; i < N+2; i++)
    {
        if (i < N)
        {
            arr1[i] = arr[temp]; 
        }
        else
        {
            if (i == N)
            {
                arr1[i] = arr[K-1]; 
            }
            else 
            {
                arr1[i] = arr[K - 2];
            }
        }
        
        temp++;
        if(temp == N)
        {
            temp = 0;
        }  
    }
    
    cout << endl;

    temp = K-1;
    for (int i=0; i < N+4; i++)
    {
        cout << arr1[temp] << " ";
        if(temp == N + 1)
        {
            temp = -1;
        }
        temp++;
    } 

    delete []arr;
    delete []arr1;

    return 0;
}