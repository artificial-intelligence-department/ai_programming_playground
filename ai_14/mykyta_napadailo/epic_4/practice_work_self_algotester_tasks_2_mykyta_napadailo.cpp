#include <iostream>
using namespace std;

int main()
{
    long n, k, a, row = 0, result = 0;
    cin >> n >> k;
    for (long i = 0; i < n; i++)
    {
        cin >> a;
        if (a >= k) row++;
        else row = 0;
        if (row > result) result = row;
    }
    cout << result;
    return 0;
}