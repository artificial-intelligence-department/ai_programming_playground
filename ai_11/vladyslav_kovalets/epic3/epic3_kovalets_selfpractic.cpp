#include <iostream>
using namespace std;

int main()
{
    int arr[]{1, 2, 5, 10, 20, 50, 100, 200, 500};
    int size1 = 9;
    long long n, suma = 0;
    cin >> n;
    for(int i = 1; i <= size1; i++ )
    {
        if (n - arr [size1 - i ] >= 0 )
        {
            while(n - arr [size1 - i ] >= 0)
            {
            suma++;
            n = n - arr[size1- i];
            }
        }

        else if (n == 0)
        {
            break;
        }

    }
    cout << suma;

}