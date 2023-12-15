#include <iostream>
using namespace std;

int main()
{
    int arr[]{1, 2, 5, 10, 20, 50, 100, 200, 500};
    int rozm = 9;
    long long n, sum = 0;
    cin >> n;
    for(int i = 1; i <= rozm; i++ )
    {
        if (n - arr [rozm - i ] >= 0 )
        {
            while(n - arr [rozm - i ] >= 0)
            {
            sum++;
            n = n - arr[rozm- i];
            }
        }

        else if (n == 0)
        {
            break;
        }

    }
    cout << sum;

}