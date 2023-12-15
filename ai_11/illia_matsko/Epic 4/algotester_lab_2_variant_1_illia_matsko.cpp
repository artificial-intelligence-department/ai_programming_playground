#include <iostream>
using namespace std;

int min(int arr[], int n)
{
    int mini=0;
    if (arr[mini] == -1) mini++;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<arr[mini] && arr[i]>=0)
        {
            mini = i;
        }
    }
    return mini;
}

int max(int arr[], int n)
{
    int maxi = 0;
    if (arr[maxi] == -1) maxi++;

    for(int i=0; i<n; i++)
    {
        if(arr[i]>arr[maxi] && arr[i]>=0)
        {
            maxi = i;
        }
    }
    return maxi;
}

int main()
{
    int n, stamina;
    cin >> n;

    int way[n], buffer[n];
    for(int i=0; i<n; i++)
    {
        cin >> way[i];
        buffer[i] = way[i];
    }

    int min_start = min(way, n);
    int max_start = max(way, n);
    if(max_start == min_start)
    {
        cout << 0;
        return 0;
    }

    buffer[max_start] = -1;
    int max_2 = max(buffer, n);
    stamina = buffer[max_2] - buffer[min_start];
    buffer[max_start] = way[max_start];

    buffer[min_start] = -1;
    int min_2 = min(buffer, n);

    if(stamina > buffer[max_start] - buffer[min_2])
    {
        cout << buffer[max_start] - buffer[min_2];
    } else {
        cout << stamina;
    }
}