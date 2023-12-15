#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{   
    int N = 100, index = 0;
    int arr[N];
    cin >> index;
    for(int i=0; i<=100; i++)
    {
        arr[i] = rand() % 50;
    }
    for (int k = 0; k<N; k++ )
    {
        cout << arr[k] << " ";
    }
    cout << "\n" << "\n";
    for (int s = N; s>0; s-- )
    {
        if (arr[s]==0)
        {
            for (int r = s; r < N - 1; r++)
            {
                arr[r] = arr[r + 1];
            }
            N--;
            s--;
        }
    }
    N++;
    for (int f = 0; f < N-index-1; f++)
    {
        arr[index+2] = arr[index+1];
    }
    arr[index+1] = 100;
    for (int b = 0; b < N; b++)
    {
        cout << arr[b] << " ";
    }
    return 0;
}