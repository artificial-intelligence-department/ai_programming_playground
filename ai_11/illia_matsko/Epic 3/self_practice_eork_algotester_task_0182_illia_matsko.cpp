#include <iostream>
using namespace std;

int main()
{
    int n, k, count=0;
    cin >> n >> k;

    int arr[n], counts[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        counts[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]>=k)
        {
            count++;
        } else {
            count = 0;
        }
        counts[i] = count;
    }

    cout << endl;

    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(counts[i]>max)
        {
            max = counts[i];
        }
    }

    cout << max;
}