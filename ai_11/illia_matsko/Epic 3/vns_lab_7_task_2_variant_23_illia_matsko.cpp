#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int new_arr[n];
    if(arr[0]%2==0)
    {
        int zsuv = arr[0];
        for(int i=0; i<n; i++)
        {
            new_arr[i] = arr[(i+zsuv)%n];
        }
    }
    else
    {
        int zsuv = arr[n-1];
        for(int i=0; i<n; i++)
        {
            int a = (i-zsuv)%n;
            new_arr[i] = arr[a<0 ? n+a : a];
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << new_arr[i] << " ";
    }
    return 0;
}